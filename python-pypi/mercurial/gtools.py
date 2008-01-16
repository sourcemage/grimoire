# gtools.py - Graphical diff and status extension for Mercurial
#
# Copyright 2007 Brad Schick, brad at gmail . com
#
# This software may be used and distributed according to the terms
# of the GNU General Public License, incorporated herein by reference.
# 
"""gtools extension provides graphical status and commit dialogs

The gtools extension provides gtk+ based graphical status, log,
and commit dialogs. Each dialogs provides a convenient way to see what 
has changed in a repository. Data is displayed in a list that can be
sorted, selected, and double-clicked to launch diff and editor tools.
Right-click context menus and toolbars provide operations like commit, 
add, view, delete, ignore, remove, revert, and refresh.

Files are diff'ed and edited in place whenever possible, so you can
make changes within external tools and save them directly back to the
working copy. To enable gtools:

   [extensions]
   hgext.gtools =

   [gtools]
   # external diff tool and options
   diffcmd = gdiff
   diffopts = -Nprc5
 
   # editor, if not specified [ui] editor is used
   editor = scite
 
   # set the fonts for the comments, diffs, and lists
   fontcomment = courier 10
   fontdiff = courier 10
   fontlist = courier 9

   # make the integrated diff window appear at the bottom or side
   diffbottom = False
 
The external diff tool is run as shown below. Unless specified otherwise,
file_rev1 and file_rev2 are the parent revision and the working copy 
respectively:

diffcmd diffopts file_rev1 file_rev2
"""

import mercurial.demandimport; mercurial.demandimport.enable()

import os
import threading
import StringIO
import sys
import shutil
import tempfile
import datetime
import cPickle

import pygtk
pygtk.require('2.0')
import gtk
import gobject
import pango

from mercurial.i18n import _
from mercurial.node import *
from mercurial import cmdutil, util, ui, hg, commands, patch
from hgext import extdiff

gtk.gdk.threads_init()

def gcommit(ui, repo, *pats, **opts):
    """graphical display for committing outstanding changes

    Displays a list of either all or specified files that can be committed
    and provides a entry field for the commit message. If a list of 
    files is omitted, all changes reported by "hg status" will be 
    committed.

    Each file in the list can be double-clicked to launch a diff or editor
    tool. Right-click context menus allow for single file operations.
    """
    dialog = GCommit(ui, repo, pats, opts, True)
    run(dialog)

def gstatus(ui, repo, *pats, **opts):
    """graphical display of changed files in the working directory

    Displays the status of files in the repository. If names are given, 
    only files that match are shown. Clean and ignored files are not 
    shown by default, but the can be added from within the dialog or the
    command-line (with -c, -i or -A)

    NOTE: status may appear to disagree with diff if permissions have
    changed or a merge has occurred. The standard diff format does not
    report permission changes and diff only reports changes relative
    to one merge parent.

    If one revision is given, it is used as the base revision.
    If two revisions are given, the difference between them is shown.

    The codes used to show the status of files are:
    M = modified
    A = added
    R = removed
    C = clean
    ! = deleted, but still tracked
    ? = not tracked
    I = ignored

    Each file in the list can be double-clicked to launch a diff or editor
    tool. Right-click context menus allow for single file operations.
    """
    dialog = GStatus(ui, repo, pats, opts, True)
    run(dialog)


def glog(ui, repo, *pats, **opts):
    """display revision history of entire repository or files

    Displays the revision history of the specified files or the entire
    project.

    File history is shown without following rename or copy history of
    files.  Use -f/--follow with a file name to follow history across
    renames and copies. --follow without a file name will only show
    ancestors or descendants of the starting revision. --follow-first
    only follows the first parent of merge revisions.

    If no revision range is specified, the default is tip:0 unless
    --follow is set, in which case the working directory parent is
    used as the starting revision.

    Each log entry in the list can be double-clicked to launch a status
    view of that revision. Diff options like --git are passed to the 
    status view when a log entry is activated.
    """
    dialog = GLog(ui, repo, pats, opts, True)
    run(dialog)


def run(dialog):
    gtk.gdk.threads_enter()
    dialog.display()
    gtk.main()
    gtk.gdk.threads_leave()


cmdtable = {
'gcommit|gci':
(gcommit,
 [('A', 'addremove', None, _('skip prompt for marking new/missing files as added/removed')),
  ('d', 'date', '', _('record datecode as commit date')),
  ('u', 'user', '', _('record user as commiter')),
  ('m', 'message', '', _('use <text> as commit message')),
  ('l', 'logfile', '', _('read commit message from <file>')),
  ('g', 'git', None, _('use git extended diff format')),
  ('c', 'check', False, _('automatically check commitable files'))] + commands.walkopts,
 _('hg gcommit [OPTION]... [FILE]...')),
'gstatus|gst':
(gstatus,
 [('A', 'all', None, _('show status of all files')),
  ('m', 'modified', None, _('show only modified files')),
  ('a', 'added', None, _('show only added files')),
  ('r', 'removed', None, _('show only removed files')),
  ('d', 'deleted', None, _('show only deleted (but tracked) files')),
  ('c', 'clean', None, _('show only files without changes')),
  ('u', 'unknown', None, _('show only unknown (not tracked) files')),
  ('i', 'ignored', None, _('show only ignored files')),
  ('',  'rev', [], _('show difference from revision')),
  ('g', 'git', None, _('use git extended diff format')),
  ('c', 'check', False, _('automatically check displayed files'))] + commands.walkopts,
 _('hg gstat [OPTION]... [FILE]...')),
'glog|ghistory':
(glog,
 [('f', 'follow', None,
   _('follow changeset history, or file history across copies and renames')),
  ('', 'follow-first', None,
   _('only follow the first parent of merge changesets')),
  ('d', 'date', '', _('show revs matching date spec')),
  ('C', 'copies', None, _('show copied files')),
  ('k', 'keyword', [], _('do case-insensitive search for a keyword')),
  ('l', 'limit', '', _('limit number of changes displayed')),
  ('r', 'rev', [], _('show the specified revision or range')),
  ('', 'removed', None, _('include revs where files were removed')),
  ('M', 'no-merges', None, _('do not show merges')),
  ('m', 'only-merges', None, _('show only merges')),
  ('P', 'prune', [], _('do not display revision or any of its ancestors')),
  ('g', 'git', None, _('use git extended diff format'))] + commands.walkopts,
_('hg glog [OPTION]... [FILE]')),
}


class SimpleMessage(gtk.MessageDialog):
    def run(self):
        response = gtk.MessageDialog.run(self)
        self.destroy()
        return response


class Prompt(SimpleMessage):
    def __init__(self, title, message, parent):
        gtk.MessageDialog.__init__(self, parent, gtk.DIALOG_MODAL, gtk.MESSAGE_INFO,
                                    gtk.BUTTONS_CLOSE)
        self.set_title(title)
        self.set_markup('<b>' + message + '</b>')


class Confirm(SimpleMessage):
    """Dialog returns gtk.RESPONSE_YES or gtk.RESPONSE_NO 
    """
    def __init__(self, title, files, parent, primary=None):
        gtk.MessageDialog.__init__(self, parent, gtk.DIALOG_MODAL, gtk.MESSAGE_QUESTION,
                                    gtk.BUTTONS_YES_NO)
        self.set_title('Confirm ' + title)
        if primary is None:
            primary = title + ' file' + ((len(files) > 1 and 's') or '') + '?'
        primary = '<b>' + primary + '</b>'
        self.set_markup(primary)
        message = ''
        for i, file in enumerate(files):
            message += '   ' + file + '\n'
            if i == 9: 
                message += '   ...\n'
                break
        self.format_secondary_text(message)


class GDialog(gtk.Window):
    """GTK+ based dialog for displaying mercurial information

    The following methods are meant to be overridden by subclasses. At this
    point GCommit is really the only intended subclass.

        parse_opts(self)
        get_title(self)
        get_minsize(self)
        get_defsize(self)
        get_tbbuttons(self)
        get_body(self)
        get_extras(self)
        prepare_display(self)
        should_live(self, widget, event)
        save_settings(self)
        load_settings(self, settings)
    """

    # "Constants"
    settings_version = 1

    def __init__(self, ui, repo, pats, opts, main):
        gtk.Window.__init__(self, gtk.WINDOW_TOPLEVEL)
        self._cwd = repo.root
        self.ui = ui
        self.ui.interactive=False
        self.repo = repo
        self.pats = pats
        self.opts = opts
        self.main = main

    ### Following methods are meant to be overridden by subclasses ###

    def parse_opts(self):
        pass


    def get_title(self):
        return ''


    def get_minsize(self):
        return (395, 200)


    def get_defsize(self):
        return self._setting_defsize 


    def get_tbbuttons(self):
        return []


    def get_body(self):
        return None


    def get_extras(self):
        return None


    def prepare_display(self):
        pass


    def should_live(self, widget=None, event=None):
        return False


    def save_settings(self):
        rect = self.get_allocation()
        return {'gdialog': (rect.width, rect.height)}


    def load_settings(self, settings):
        if settings:
            self._setting_defsize = settings['gdialog']
        else:
            self._setting_defsize = (678, 585)

    ### End of overridable methods ###

    def display(self):
        self._parse_config()
        self._load_settings()
        self._setup_gtk()
        self._parse_opts()
        self.prepare_display()
        self.show_all()


    def test_opt(self, opt):
        return opt in self.opts and self.opts[opt]


    def _parse_config(self):
        # defaults    
        self.fontcomment = 'courier 10'
        self.fontdiff = 'courier 10'
        self.fontlist = 'courier 9'
        self.diffopts = ''
        self.diffcmd = ''
        self.diffbottom = ''

        for attr, setting in self.ui.configitems('gtools'):
            if setting : setattr(self, attr, setting)

        if not self.diffcmd :
            if not self.diffopts : self.diffopts = '-Npru'
            self.diffcmd = 'diff'

        if not self.diffbottom or self.diffbottom.lower() == 'false' or self.diffbottom == '0':
            self.diffbottom = False
        else:
            self.diffbottom = True


    def _parse_opts(self):
        # Remove dry_run since Hg only honors it for certain commands
        self.opts['dry_run'] = False
        self.opts['force_editor'] = False
        self.parse_opts()


    def merge_opts(self, defaults, mergelist=()):
        """Merge default options with the specified local options and globals.
        Results is defaults + merglist + globals
        """
        newopts = {}
        for hgopt in defaults:
            newopts[hgopt[1].replace('-', '_')] = hgopt[2]
        for mergeopt in mergelist:
            newopts[mergeopt] = self.opts[mergeopt]
        newopts.update(self.global_opts())
        return newopts


    def global_opts(self):
        globals = {}
        hgglobals = [opt[1].replace('-', '_') for opt in commands.globalopts if opt[1] != 'help']
        for key in self.opts:
            if key in  hgglobals :
                globals[key] = self.opts[key]
        return globals


    def count_revs(self):
        cnt = 0
        if self.test_opt('rev'):
            for rev in self.opts['rev']:
                cnt += len(rev.split(cmdutil.revrangesep, 1))
        return cnt


    def make_toolbutton(self, stock, label, handler, userdata=None):
        tbutton = gtk.ToolButton(stock)
        tbutton.set_use_underline(True)
        tbutton.set_label(label)
        tbutton.connect('clicked', handler, userdata)
        return tbutton


    def _setup_gtk(self):
        self.set_title(self.get_title())
        
        # Minimum size
        minx, miny = self.get_minsize()
        self.set_size_request(minx, miny)
        # Initial size
        defx, defy = self.get_defsize()
        self.set_default_size(defx, defy)
        
        vbox = gtk.VBox(False, 0)
        self.add(vbox)
        
        toolbar = gtk.Toolbar()
        tbuttons =  self.get_tbbuttons()
        for tbutton in tbuttons:
            toolbar.insert(tbutton, -1)

        vbox.pack_start(toolbar, False, False, 0)

        # Subclass returns the main body
        body = self.get_body()
        vbox.pack_start(body, True, True, 0)
        
        hbox = gtk.HBox(False, 0)
        hbox.set_border_width(6)
        vbox.pack_end(hbox, False, False, 0)
        
        bbox = gtk.HButtonBox()
        bbox.set_layout(gtk.BUTTONBOX_EDGE)
        hbox.pack_end(bbox, False, False)

        if self.main:
            button = gtk.Button(stock=gtk.STOCK_QUIT)
        else:
            button = gtk.Button(stock=gtk.STOCK_CLOSE)

        button.connect('clicked', self._quit_clicked)
        bbox.pack_end(button, False, False)
        self.connect('destroy', self._destroying)
        self.connect('delete_event', self.should_live)

        # Subclass provides extra stuff to left of Quit button
        extras = self.get_extras()
        if extras:
            hbox.pack_start(extras, False, False)


    def _quit_clicked(self, button):
        if not self.should_live():
            self.destroy()


    def _destroying(self, gtkobj):
        try:
            file = None
            settings = self.save_settings()
            versioned = (GDialog.settings_version, settings)
            dirname = os.path.join(os.path.expanduser('~'), '.hgext/gtools')
            filename = os.path.join(dirname, self.__class__.__name__)
            try:
                if not os.path.exists(dirname):
                    os.makedirs(dirname)
                file = open(filename, 'wb')
                cPickle.dump(versioned, file, cPickle.HIGHEST_PROTOCOL)
            except (IOError, cPickle.PickleError):
                pass
        finally:
            if file:
                file.close()
            if self.main:
                gtk.main_quit()


    def _load_settings(self):
        try:
            file = None
            settings = None
            dirname = os.path.join(os.path.expanduser('~'), '.hgext/gtools')
            filename = os.path.join(dirname, self.__class__.__name__)
            try:
                file = open(filename, 'rb')
                versioned = cPickle.load(file)
                if versioned[0] == GDialog.settings_version:
                    settings = versioned[1]
            except (IOError, cPickle.PickleError), inst:
                pass
        finally:
            if file:
                file.close()
            self.load_settings(settings)


    def restore_cwd(self):
        # extdiff works on relative directories to avoid showing temp paths. Since another thread
        # could be running that changed cwd, we always need to set it back. This is a race condition
        # but not likely to be a problem.
        os.chdir(self._cwd)


    def _hg_call_wrapper(self, title, command, showoutput=True):
        """Run the specified command and display any resulting aborts, messages, 
        and errors 
        """
        self.restore_cwd()
        textout = ''
        saved = sys.stderr
        errors = StringIO.StringIO()
        try:
            sys.stderr = errors
            self.ui.pushbuffer()
            try:
                command()
            except util.Abort, inst:
                Prompt(title + ' Aborted', str(inst), self).run()
                return False, ''
        finally:
            sys.stderr = saved
            textout = self.ui.popbuffer() 
            prompttext = ''
            if showoutput:
                prompttext = textout + '\n'
            prompttext += errors.getvalue()
            errors.close()
            if len(prompttext) > 1:
                Prompt(title + ' Messages and Errors', prompttext, self).run()

        return True, textout



class GLog(GDialog):
    """GTK+ based dialog for displaying repository logs
    """

    # "Constants"
    block_count = 150


    def get_title(self):
        return os.path.basename(self.repo.root) + ' log ' + ':'.join(self.opts['rev']) + ' ' + ' '.join(self.pats)


    def parse_opts(self):
        # Disable quiet to get full log info
        self.ui.quiet = False


    def get_tbbuttons(self):
        return [self.make_toolbutton(gtk.STOCK_REFRESH, 're_fresh', self._refresh_clicked),
                     gtk.SeparatorToolItem()]


    def prepare_display(self):
        self.refreshing = False
        self._last_rev = -999
        # If the log load failed, no reason to continue
        if not self.reload_log():
            raise util.Abort('could not load log')


    def save_settings(self):
        settings = GDialog.save_settings(self)
        settings['glog'] = self._vpaned.get_position()
        return settings


    def load_settings(self, settings):
        GDialog.load_settings(self, settings)
        if settings:
            self._setting_vpos = settings['glog']
        else:
            self._setting_vpos = -1


    def _hg_log(self, rev, pats, verbose):
        def dohglog():
            self.restore_cwd()
            self.repo.dirstate.invalidate()
            commands.log(self.ui, self.repo, *pats, **self.opts)

        logtext = ''
        success = False
        saved_revs = self.opts['rev']
        saved_verbose = self.ui.verbose
        try:
            self.opts['rev'] = rev
            self.ui.verbose = verbose
            success, logtext = self._hg_call_wrapper('Log', dohglog, False)
        finally:
            self.opts['rev'] = saved_revs
            self.ui.verbose = saved_verbose
        return success, logtext


    def reload_log(self):
        """Clear out the existing ListStore model and reload it from the repository. 
        """
        # If the last refresh is still being processed, then do nothing
        if self.refreshing:
            return False

        # For long logs this is the slowest part, but given the current
        # Hg API doesn't allow it to be easily processed in chuncks
        success, logtext = self._hg_log(self.opts['rev'], self.pats, False)
        if not success:
            return False

        if not logtext:
            return True

        # Currently selected file
        iter = self.tree.get_selection().get_selected()[1]
        if iter:
            reselect = self.model[iter][0]
        else:
            reselect = None

        # Load the new data into the tree's model
        self.tree.hide()
        self.model.clear()

        # Generator that parses and inserts log entries
        def inserter(logtext):
            while logtext:
                blocks = logtext.strip('\n').split('\n\n', GLog.block_count)
                if len(blocks) > GLog.block_count:
                    logtext = blocks[GLog.block_count]
                    del blocks[GLog.block_count]
                else:
                    logtext = None
    
                for block in blocks:
                    # defaults
                    log = { 'user' : 'missing', 'summary' : '' }
                    lines = block.split('\n')
                    parents = []
                    for line in lines:
                        line = util.fromlocal(line)
                        sep = line.index(':')
                        info = line[0:sep]
                        value = line[sep+1:].strip()
    
                        if info == 'changeset':
                            log['rev'] = value.split(':')[0]
                        elif info == 'parent':
                            parents.append(long(value.split(':')[0]))
                        else:
                            log[info] = value
    
                    self.model.append((log['rev'], log['user'], log['summary'], log['date'], 
                                       util.strdate(util.tolocal(log['date']), '%a %b %d %H:%M:%S %Y', {})[0],
                                       parents))
                yield logtext is not None


        # Insert entries during idle to improve response time, but run
        # the first batch synchronously to attempt the reselect below
        gen = inserter(logtext)
        self.refreshing = gen.next()

        # If insert didn't finish, setup idle processing for the remainder
        if self.refreshing:
            def doidle():
                self.refreshing = gen.next()
                return self.refreshing
            gobject.idle_add(doidle)

        selection = self.tree.get_selection()
        for row in self.model:
            if row[0] == reselect:
                selection.select_iter(row.iter)
                break
        else:
            self.tree.scroll_to_cell((0,))
            selection.select_path((0,))

        self.tree.show()
        self.tree.grab_focus()
        return True


    def load_details(self, rev, parents):
        save_removed = self.opts['removed'] 
        self.opts['removed'] = False
        success, logtext = self._hg_log(rev, [], True)
        self.opts['removed'] = save_removed

        if not success:
            self.details_text.set_buffer(gtk.TextBuffer())
            return False

        buffer = gtk.TextBuffer()
        buff_iter = buffer.get_start_iter()
        buffer.create_tag('changeset', foreground='#000090', paragraph_background='#F0F0F0')
        buffer.create_tag('date', foreground='#000090', paragraph_background='#F0F0F0')
        buffer.create_tag('files', foreground='#5C5C5C', paragraph_background='#F0F0F0')
        if parents == 1:
            buffer.create_tag('parent', foreground='#900000', paragraph_background='#F0F0F0')
        elif parents == 2:
            buffer.create_tag('parent', foreground='#006400', paragraph_background='#F0F0F0')

        lines = logtext.split('\n')
        lines_iter = iter(lines)

        for line in lines_iter:
            line = util.fromlocal(line)
            if line.startswith('changeset:'):
                buffer.insert_with_tags_by_name(buff_iter, line + '\n', 'changeset')
            if line.startswith('date:'):
                buffer.insert_with_tags_by_name(buff_iter, line + '\n', 'date')
            elif line.startswith('parent:'):
                buffer.insert_with_tags_by_name(buff_iter, line + '\n', 'parent')
            elif line.startswith('files:'):
                buffer.insert_with_tags_by_name(buff_iter, line + '\n', 'files')
            elif line.startswith('description:'):
                buffer.insert(buff_iter, '\n')
                break;

        for line in lines_iter:
            line = util.fromlocal(line)
            buffer.insert(buff_iter, line + '\n')

        self.details_text.set_buffer(buffer)
        return True


    def _search_in_tree(self, model, column, key, iter, data):
        """Searches all fields shown in the tree when the user hits crtr+f,
        not just the ones that are set via tree.set_search_column.
        Case insensitive
        """
        key = key.lower()
        searchable = [x.lower() for x in (
                        model.get_value(iter,0), #rev id (local)
                        model.get_value(iter,1), #author
                        model.get_value(iter,2), #summary
                        )]
        for field in searchable:
            if field.find(key) != -1:
                return False
        return True


    def get_body(self):
        self._menu = gtk.Menu()
        self._menu.set_size_request(90, -1)
        menuitem = gtk.MenuItem('_status', True)
        menuitem.connect('activate', self._show_status)
        menuitem.set_border_width(1)
        self._menu.append(menuitem)
        menuitem = gtk.MenuItem("_export patch",True)
        menuitem.connect('activate',self._export_patch)
        menuitem.set_border_width(1)
        self._menu.append(menuitem)
        self._menu.show_all()

        self.model = gtk.ListStore(str, str, str, str, long, object)
        self.model.set_default_sort_func(self._sort_by_rev)

        self.tree = gtk.TreeView(self.model)
        self.tree.connect('button-release-event', self._tree_button_release)
        self.tree.connect('popup-menu', self._tree_popup_menu)
        self.tree.connect('row-activated', self._tree_row_act)
        self.tree.set_reorderable(False)
        self.tree.set_enable_search(True)
        self.tree.set_search_equal_func(self._search_in_tree,None)
        self.tree.get_selection().set_mode(gtk.SELECTION_SINGLE)
        self.tree.get_selection().connect('changed', self._tree_selection_changed)
        self.tree.set_rubber_banding(False)
        self.tree.modify_font(pango.FontDescription(self.fontlist))
        self.tree.set_rules_hint(True) 
        
        changeset_cell = gtk.CellRendererText()
        user_cell = gtk.CellRendererText()
        summary_cell = gtk.CellRendererText()
        date_cell = gtk.CellRendererText()
        
        col0 = gtk.TreeViewColumn('rev', changeset_cell)
        col0.add_attribute(changeset_cell, 'text', 0)
        col0.set_cell_data_func(changeset_cell, self._text_color)
        col0.set_sort_column_id(0)
        col0.set_resizable(False)
        
        col1 = gtk.TreeViewColumn('user', user_cell)
        col1.add_attribute(user_cell, 'text', 1)
        col1.set_cell_data_func(user_cell, self._text_color)
        col1.set_sort_column_id(1)
        col1.set_resizable(True)
        
        col2 = gtk.TreeViewColumn('summary', summary_cell)
        col2.add_attribute(summary_cell, 'text', 2)
        col2.set_cell_data_func(summary_cell, self._text_color)
        col2.set_sort_column_id(2)
        col2.set_resizable(True)

        col3 = gtk.TreeViewColumn('date', date_cell)
        col3.add_attribute(date_cell, 'text', 3)
        col3.set_cell_data_func(date_cell, self._text_color)
        col3.set_sort_column_id(4)
        col3.set_resizable(True)

        self.tree.append_column(col0)
        self.tree.append_column(col1)
        self.tree.append_column(col2)
        self.tree.append_column(col3)
        self.tree.set_headers_clickable(True)
        
        scroller = gtk.ScrolledWindow()
        scroller.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        scroller.add(self.tree)
        
        tree_frame = gtk.Frame()
        tree_frame.set_shadow_type(gtk.SHADOW_ETCHED_IN)
        tree_frame.add(scroller)

        details_frame = gtk.Frame()
        details_frame.set_shadow_type(gtk.SHADOW_ETCHED_IN)
        scroller = gtk.ScrolledWindow()
        scroller.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        details_frame.add(scroller)
        
        self.details_text = gtk.TextView()
        self.details_text.set_wrap_mode(gtk.WRAP_WORD)
        self.details_text.set_editable(False)
        self.details_text.modify_font(pango.FontDescription(self.fontcomment))
        scroller.add(self.details_text)

        self._vpaned = gtk.VPaned()
        self._vpaned.pack1(tree_frame, True, False)
        self._vpaned.pack2(details_frame, True, True)
        self._vpaned.set_position(self._setting_vpos)
        return self._vpaned


    def _sort_by_rev(self, model, iter1, iter2):
        lhs, rhs = (model.get_value(iter1, 0), model.get_value(iter2, 0))

        # GTK+ bug that calls sort before a full row is inserted causing values to be None.
        if None in (lhs, rhs) :
            return 0

        result = long(rhs) - long(lhs)
        return min(max(result, -1), 1)


    def _text_color(self, column, text_renderer, list, row_iter):
        parents = list[row_iter][5]
        if len(parents) == 2:
            text_renderer.set_property('foreground', '#006400')
        elif len(parents) == 1:
            text_renderer.set_property('foreground', '#900000')
        else:
            text_renderer.set_property('foreground', 'black')


    def _show_status(self, menuitem):
        row = self.model[self.tree.get_selection().get_selected()[1]]
        rev = long(row[0])
        parents = row[5]
        if len(parents) == 0:
            parents = [rev-1]

        for parent in parents:
            statopts = self.merge_opts(cmdtable['gstatus|gst'][1], ('include', 'exclude', 'git'))
            statopts['rev'] = ['%u:%u' % (parent, rev)]
            statopts['modified'] = True
            statopts['added'] = True
            statopts['removed'] = True
            dialog = GStatus(self.ui, self.repo, [], statopts, False)
            dialog.display()
        return True


    def _export_patch(self, menuitem):
        row = self.model[self.tree.get_selection().get_selected()[1]]
        rev = long(row[0])
        fd = NativeSaveFileDialogWrapper(Title = "Save patch to")
        result = fd.run()

        if result:
            # In case new export args are added in the future, merge the hg defaults
            exportOpts= self.merge_opts(commands.table['^export'][1], ())
            exportOpts['output'] = result
            def dohgexport():
                commands.export(self.ui,self.repo,str(rev),**exportOpts)
            success, outtext = self._hg_call_wrapper("Export",dohgexport,False)


    def _tree_selection_changed(self, selection):
        ''' Update the details text '''
        if selection.count_selected_rows() == 0:
            return False
        rev = [self.model[selection.get_selected()[1]][0]]
        if rev != self._last_rev:
            self._last_rev = rev
            parents = self.model[selection.get_selected()[1]][5]
            self.load_details(rev, len(parents))

        return False


    def _refresh_clicked(self, toolbutton, data=None):
        self.reload_log()
        return True


    def _tree_button_release(self, widget, event) :
        if event.button == 3 and not (event.state & (gtk.gdk.SHIFT_MASK | gtk.gdk.CONTROL_MASK)):
            self._tree_popup_menu(widget, event.button, event.time)
        return False


    def _tree_popup_menu(self, widget, button=0, time=0) :
        self._menu.popup(None, None, None, button, time)
        return True


    def _tree_row_act(self, tree, path, column) :
        """Default action is the first entry in the context menu
        """
        self._menu.get_children()[0].activate()
        return True



class GStatus(GDialog):
    """GTK+ based dialog for displaying repository status

    Also provides related operations like add, delete, remove, revert, refresh,
    ignore, diff, and edit.

    The following methods are meant to be overridden by subclasses. At this
    point GCommit is really the only intended subclass.

        auto_check(self)
        get_menu_info(self)
    """

    ### Following methods are meant to be overridden by subclasses ###

    def auto_check(self):
        if self.test_opt('check'):
            for entry in self.model : entry[0] = True


    def get_menu_info(self):
        """Returns menu info in this order: merge, addrem, unknown, clean, ignored, deleted 
        """
        return ((('_difference', self._diff_file), ('_view right', self._view_file), 
                    ('view _left', self._view_left_file), ('_revert', self._revert_file), ('l_og', self._log_file)),
                (('_difference', self._diff_file), ('_view', self._view_file), 
                    ('_revert', self._revert_file), ('l_og', self._log_file)),
                (('_view', self._view_file), ('_delete', self._delete_file), 
                    ('_add', self._add_file), ('_ignore', self._ignore_file)),
                (('_view', self._view_file), ('re_move', self._remove_file), ('l_og', self._log_file)),
                (('_view', self._view_file), ('_delete', self._delete_file)),
                (('_view', self._view_file), ('_revert', self._revert_file), 
                    ('re_move', self._remove_file), ('l_og', self._log_file)))

    ### End of overridable methods ###


    ### Overrides of base class methods ###

    def parse_opts(self):
        self._ready = False

        # Determine which files to display
        if self.test_opt('all'):
            for check in self._show_checks.values():
                check.set_active(True)
        else:
            set = False
            for opt in self.opts :
                if opt in self._show_checks and self.opts[opt]:
                    set = True
                    self._show_checks[opt].set_active(True)
            if not set:
                for check in [item[1] for item in self._show_checks.iteritems() 
                              if item[0] in ('modified', 'added', 'removed', 
                                             'deleted', 'unknown')]:
                    check.set_active(True)


    def get_title(self):
        return os.path.basename(self.repo.root) + ' status ' + ':'.join(self.opts['rev'])  + ' ' + ' '.join(self.pats)


    def get_defsize(self):
        return self._setting_defsize


    def get_tbbuttons(self):
        tbuttons = [self.make_toolbutton(gtk.STOCK_REFRESH, 're_fresh', self._refresh_clicked),
                     gtk.SeparatorToolItem()]

        if self.count_revs() < 2:
            tbuttons += [self.make_toolbutton(gtk.STOCK_MEDIA_REWIND, 're_vert', self._revert_clicked),
                         self.make_toolbutton(gtk.STOCK_ADD, '_add', self._add_clicked),
                         self.make_toolbutton(gtk.STOCK_DELETE, '_delete', self._delete_clicked),
                         gtk.SeparatorToolItem(),
                         self.make_toolbutton(gtk.STOCK_YES, '_select', self._sel_desel_clicked, True),
                         self.make_toolbutton(gtk.STOCK_NO, '_deselect', self._sel_desel_clicked, False),
                         gtk.SeparatorToolItem()]

        self.showdiff_toggle = gtk.ToggleToolButton(gtk.STOCK_JUSTIFY_FILL)
        self.showdiff_toggle.set_use_underline(True)
        self.showdiff_toggle.set_label('_show diff')
        self.showdiff_toggle.set_active(False)
        self._showdiff_toggled_id = self.showdiff_toggle.connect('toggled', self._showdiff_toggled )
        tbuttons.append(self.showdiff_toggle)
        return tbuttons


    def save_settings(self):
        settings = GDialog.save_settings(self)
        settings['gstatus'] = (self._diffpane.get_position(), self._setting_lastpos)
        return settings


    def load_settings(self, settings):
        GDialog.load_settings(self, settings)
        if settings:
            mysettings = settings['gstatus']
            self._setting_pos = mysettings[0]
            self._setting_lastpos = mysettings[1]
        else:
            self._setting_pos = 64000
            self._setting_lastpos = 270


    def get_body(self):
        self.connect('map-event', self._displayed)

        # TODO: should generate menus dynamically during right-click, currently
        # there can be entires that are not always supported or relavant.
        merge, addrem, unknown, clean, ignored, deleted  = self.get_menu_info()
        merge_menu = self.make_menu(merge)
        addrem_menu = self.make_menu(addrem)
        unknown_menu = self.make_menu(unknown)
        clean_menu = self.make_menu(clean)
        ignored_menu = self.make_menu(ignored)
        deleted_menu = self.make_menu(deleted)

        # Dictionary with a key of file-stat and values containing context-menus
        self._menus = {}
        self._menus['M'] = merge_menu
        self._menus['A'] = addrem_menu
        self._menus['R'] = addrem_menu
        self._menus['?'] = unknown_menu
        self._menus['C'] = clean_menu
        self._menus['I'] = ignored_menu
        self._menus['!'] = deleted_menu

        self.model = gtk.ListStore(bool, str, str)
        self.model.set_sort_func(1001, self._sort_by_stat)
        self.model.set_default_sort_func(self._sort_by_stat)

        self.tree = gtk.TreeView(self.model)
        self.tree.connect('button-press-event', self._tree_button_press)
        self.tree.connect('button-release-event', self._tree_button_release)
        self.tree.connect('popup-menu', self._tree_popup_menu)
        self.tree.connect('row-activated', self._tree_row_act)
        self.tree.connect('key-press-event', self._tree_key_press)
        self.tree.set_reorderable(False)
        self.tree.set_enable_search(True)
        self.tree.set_search_column(2)
        self.tree.get_selection().set_mode(gtk.SELECTION_MULTIPLE)
        self.tree.get_selection().connect('changed', self._tree_selection_changed, False)
        self.tree.set_rubber_banding(True)
        self.tree.modify_font(pango.FontDescription(self.fontlist))
        self.tree.set_headers_clickable(True)
        
        toggle_cell = gtk.CellRendererToggle()
        toggle_cell.connect('toggled', self._select_toggle)
        toggle_cell.set_property('activatable', True)

        path_cell = gtk.CellRendererText()
        stat_cell = gtk.CellRendererText()

        if self.count_revs() < 2:
            col0 = gtk.TreeViewColumn('select', toggle_cell)
            col0.add_attribute(toggle_cell, 'active', 0)
            col0.set_sort_column_id(0)
            col0.set_resizable(False)
            self.tree.append_column(col0)
        
        col1 = gtk.TreeViewColumn('st', stat_cell)
        col1.add_attribute(stat_cell, 'text', 1)
        col1.set_cell_data_func(stat_cell, self._text_color)
        col1.set_sort_column_id(1001)
        col1.set_resizable(False)
        self.tree.append_column(col1)
        
        col2 = gtk.TreeViewColumn('path', path_cell)
        col2.add_attribute(path_cell, 'text', 2)
        col2.set_cell_data_func(path_cell, self._text_color)
        col2.set_sort_column_id(2)
        col2.set_resizable(True)
        self.tree.append_column(col2)
       
        scroller = gtk.ScrolledWindow()
        scroller.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        scroller.add(self.tree)
        
        tree_frame = gtk.Frame()
        tree_frame.set_shadow_type(gtk.SHADOW_ETCHED_IN)
        tree_frame.add(scroller)

        diff_frame = gtk.Frame()
        diff_frame.set_shadow_type(gtk.SHADOW_ETCHED_IN)
        scroller = gtk.ScrolledWindow()
        scroller.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        diff_frame.add(scroller)
        
        self.diff_text = gtk.TextView()
        self.diff_text.set_wrap_mode(gtk.WRAP_NONE)
        self.diff_text.set_editable(False)
        self.diff_text.modify_font(pango.FontDescription(self.fontdiff))
        scroller.add(self.diff_text)

        if self.diffbottom:
            self._diffpane = gtk.VPaned()
        else:
            self._diffpane = gtk.HPaned()

        self._diffpane.pack1(tree_frame, True, False)
        self._diffpane.pack2(diff_frame, True, True)
        self._diffpane.set_position(self._setting_pos)
        self._diffpane_moved_id = self._diffpane.connect('notify::position', self._diffpane_moved)
        return self._diffpane


    def get_extras(self):
        table = gtk.Table(rows=2, columns=3)
        table.set_col_spacings(8)

        self._show_checks = {}
        row, col = 0, 0
        checks = ('modified', 'added', 'removed')
        if self.count_revs() <= 1:
            checks += ('deleted', 'unknown', 'clean', 'ignored')

        for type in checks:
            check = gtk.CheckButton('_' + type)
            check.connect('toggled', self._show_toggle, type)
            table.attach(check, col, col+1, row, row+1)
            self._show_checks[type] = check
            col += row
            row = not row
        return table
        

    def prepare_display(self):
        self._ready = True
        self._last_files = []
        # If the status load failed, no reason to continue
        if not self.reload_status():
            raise util.Abort('could not load status')
        self.auto_check()


    def _displayed(self, widget, event):
        self._diffpane_moved(self._diffpane)
        return False


    def should_live(self, widget=None, event=None):
        return False

    ### End of overrides ###

    def _do_reload_status(self):
        """Clear out the existing ListStore model and reload it from the repository status. 
        Also recheck and reselect files that remain in the list.
        """
        self.restore_cwd()
        self.repo.dirstate.invalidate()

        # The following code was copied from the status function in mercurial\commands.py
        # and modified slightly to work here
        
        # node2 is None (the working dir) when 0 or 1 rev is specificed
        self._node1, self._node2 = cmdutil.revpair(self.repo, self.opts.get('rev'))
    
        files, matchfn, anypats = cmdutil.matchpats(self.repo, self.pats, self.opts)
        cwd = (self.pats and self.repo.getcwd()) or ''
        modified, added, removed, deleted, unknown, ignored, clean = [
            n for n in self.repo.status(node1=self._node1, node2=self._node2, files=files,
                                 match=matchfn,
                                 list_ignored=self.test_opt('ignored'),
                                 list_clean=self.test_opt('clean'))]

        changetypes = (('modified', 'M', modified),
                       ('added', 'A', added),
                       ('removed', 'R', removed),
                       ('deleted', '!', deleted),
                       ('unknown', '?', unknown),
                       ('ignored', 'I', ignored))
    
        explicit_changetypes = changetypes + (('clean', 'C', clean),)

        # List of the currently checked and selected files to pass on to the new data
        recheck = [entry[2] for entry in self.model if entry[0]]
        reselect = [self.model[iter][2] for iter in self.tree.get_selection().get_selected_rows()[1]]

        # Load the new data into the tree's model
        self.tree.hide()
        self.model.clear()
    
        for opt, char, changes in ([ct for ct in explicit_changetypes
                                    if self.test_opt(ct[0])] or changetypes) :
            for file in changes:
                file = util.localpath(file)
                self.model.append([file in recheck, char, file])

        selection = self.tree.get_selection()
        selected = False
        for row in self.model:
            if row[2] in reselect:
                selection.select_iter(row.iter)
                selected = True

        if not selected:
            selection.select_path((0,))

        self.tree.show()
        self.tree.grab_focus()
        return True


    def reload_status(self):
        if not self._ready: return False
        success, outtext = self._hg_call_wrapper('Status', self._do_reload_status)
        return success


    def make_menu(self, entries):
        menu = gtk.Menu()
        for entry in entries:
            menu.append(self._make_menuitem(entry[0], entry[1]))
        menu.set_size_request(90, -1)
        menu.show_all()
        return menu


    def _make_menuitem(self, label, handler):
        menuitem = gtk.MenuItem(label, True)
        menuitem.connect('activate', self._context_menu_act, handler)
        menuitem.set_border_width(1)
        return menuitem


    def _select_toggle(self, cellrenderer, path):
        self.model[path][0] = not self.model[path][0]
        return True


    def _show_toggle(self, check, type):
        self.opts[type] = check.get_active()
        self.reload_status()
        return True


    def _sort_by_stat(self, model, iter1, iter2):
        order = 'MAR!?IC'
        lhs, rhs = (model.get_value(iter1, 1), model.get_value(iter2, 1))

        # GTK+ bug that calls sort before a full row is inserted causing values to be None.
        # When this happens, just return any value since the call is irrelevant and will be
        # followed by another with the correct (non-None) value
        if None in (lhs, rhs) :
            return 0

        result = order.find(lhs) - order.find(rhs)
        return min(max(result, -1), 1)
        

    def _text_color(self, column, text_renderer, list, row_iter):
        stat = list[row_iter][1]
        if stat == 'M':  
            text_renderer.set_property('foreground', '#000090')
        elif stat == 'A':
            text_renderer.set_property('foreground', '#006400')
        elif stat == 'R':
            text_renderer.set_property('foreground', '#900000')
        elif stat == 'C':
            text_renderer.set_property('foreground', 'black')
        elif stat == '!':
            text_renderer.set_property('foreground', 'red')
        elif stat == '?':
            text_renderer.set_property('foreground', '#AA5000')
        elif stat == 'I':
            text_renderer.set_property('foreground', 'black')
        else:
            text_renderer.set_property('foreground', 'black')


    def _diff_file(self, stat, file):
        def dodiff():
            self.restore_cwd()
            extdiff.dodiff(self.ui, self.repo, self.diffcmd, [self.diffopts],
                            [file], self.opts)

        thread = threading.Thread(target=dodiff, name='diff:'+file)
        thread.setDaemon(True)
        thread.start()


    def _view_file(self, stat, file, force_left=False):
        def doedit():
            pathroot = self.repo.root
            tmproot = None
            copynode = None
            try:
                # if we aren't looking at the wc, copy the node...
                if stat in 'R!' or force_left:
                    copynode = self._node1
                elif self._node2:
                    copynode = self._node2

                if copynode:
                    tmproot = tempfile.mkdtemp(prefix='gtools.')
                    copydir = extdiff.snapshot_node(self.ui, self.repo, [util.pconvert(file)],
                                                     copynode, tmproot)
                    pathroot = os.path.join(tmproot, copydir)

                file_path = os.path.join(pathroot, file)
                editor = (os.environ.get('HGEDITOR') or
                        self.ui.config('gtools', 'editor') or
                        self.ui.config('ui', 'editor') or
                        os.environ.get('EDITOR', 'vi'))
                util.system("%s \"%s\"" % (editor, file_path),
                            environ={'HGUSER': self.ui.username()},
                            onerr=util.Abort, errprefix=_('edit failed'))
            finally:
                if tmproot:
                    shutil.rmtree(tmproot)

        thread = threading.Thread(target=doedit, name='edit:'+file)
        thread.setDaemon(True)
        thread.start()


    def _view_left_file(self, stat, file):
        return self._view_file(stat, file, True)


    def _remove_file(self, stat, file):
        self._hg_remove([file])
        return True


    def _hg_remove(self, files):
        if self.count_revs() > 1:
            Prompt('Nothing Removed', 'Remove is not enabled when multiple revisions are specified.', self).run()
            return

        # Create new opts, so nothing unintented gets through
        removeopts = self.merge_opts(commands.table['^remove|rm'][1], ('include', 'exclude'))
        def dohgremove():
            commands.remove(self.ui, self.repo, *files, **removeopts)
        success, outtext = self._hg_call_wrapper('Remove', dohgremove)
        if success:
            self.reload_status()


    def _tree_selection_changed(self, selection, force):
        ''' Update the diff text '''
        def dohgdiff():
            self.restore_cwd()
            difftext = StringIO.StringIO()
            try:
                if len(files) != 0:
                    fns, matchfn, anypats = cmdutil.matchpats(self.repo, files, self.opts)
                    patch.diff(self.repo, self._node1, self._node2, fns, match=matchfn,
                               fp=difftext, opts=patch.diffopts(self.ui, self.opts))

                buffer = gtk.TextBuffer()
                buffer.create_tag('removed', foreground='#900000')
                buffer.create_tag('added', foreground='#006400')
                buffer.create_tag('position', foreground='#FF8000')
                buffer.create_tag('header', foreground='#000090')

                difftext.seek(0)
                iter = buffer.get_start_iter()
                for line in difftext:
                    line = util.fromlocal(line)
                    if line.startswith('---') or line.startswith('+++'):
                        buffer.insert_with_tags_by_name(iter, line, 'header')
                    elif line.startswith('-'):
                        buffer.insert_with_tags_by_name(iter, line, 'removed')
                    elif line.startswith('+'):
                        buffer.insert_with_tags_by_name(iter, line, 'added')
                    elif line.startswith('@@'):
                        buffer.insert_with_tags_by_name(iter, line, 'position')
                    else:
                        buffer.insert(iter, line)

                self.diff_text.set_buffer(buffer)
            finally:
                difftext.close()

        if self.showdiff_toggle.get_active():
            files = [self.model[iter][2] for iter in self.tree.get_selection().get_selected_rows()[1]]
            if force or files != self._last_files:
                self._last_files = files
                self._hg_call_wrapper('Diff', dohgdiff)
        return False


    def _showdiff_toggled(self, togglebutton, data=None):
        # prevent movement events while setting position
        self._diffpane.handler_block(self._diffpane_moved_id)

        if togglebutton.get_active():
            self._tree_selection_changed(self.tree.get_selection(), True)
            self._diffpane.set_position(self._setting_lastpos)
        else:
            self._setting_lastpos = self._diffpane.get_position()
            self._diffpane.set_position(64000)
            self.diff_text.set_buffer(gtk.TextBuffer())

        self._diffpane.handler_unblock(self._diffpane_moved_id)
        return True


    def _diffpane_moved(self, paned, data=None):
        # prevent toggle events while setting toolbar state
        self.showdiff_toggle.handler_block(self._showdiff_toggled_id)
        if self.diffbottom:
            sizemax = self._diffpane.get_allocation().height
        else:
            sizemax = self._diffpane.get_allocation().width

        if self.showdiff_toggle.get_active():
            if paned.get_position() >=  sizemax - 55:
                self.showdiff_toggle.set_active(False)
                self.diff_text.set_buffer(gtk.TextBuffer())
        elif paned.get_position() < sizemax - 55:
            self.showdiff_toggle.set_active(True)
            self._tree_selection_changed(self.tree.get_selection(), True)

        self.showdiff_toggle.handler_unblock(self._showdiff_toggled_id)
        return False
        

    def _refresh_clicked(self, toolbutton, data=None):
        self.reload_status()
        return True


    def _revert_clicked(self, toolbutton, data=None):
        revert_list = self._relevant_files('MAR!')
        if len(revert_list) > 0:
            self._hg_revert(revert_list)
        else:
            Prompt('Nothing Reverted', 'No revertable files selected', self).run()
        return True


    def _revert_file(self, stat, file):
        self._hg_revert([file])
        return True


    def _log_file(self, stat, file):
        # Might want to include 'rev' here... trying without
        statopts = self.merge_opts(cmdtable['glog|ghistory'][1], ('include', 'exclude', 'git'))
        dialog = GLog(self.ui, self.repo, [file], statopts, False)
        dialog.display()
        return True


    def _hg_revert(self, files):
        if self.count_revs() > 1:
            Prompt('Nothing Reverted', 'Revert is not enabled when multiple revisions are specified.', self).run()
            return

        # Create new opts,  so nothing unintented gets through.
        revertopts = self.merge_opts(commands.table['^revert'][1], ('include', 'exclude', 'rev'))
        def dohgrevert():
            commands.revert(self.ui, self.repo, *files, **revertopts)

        # TODO: Ask which revision when multiple parents (currently just shows abort message)
        # TODO: Don't need to prompt when reverting added or removed files
        if self.count_revs() == 1:
            # rev options needs extra tweaking since is not an array for revert command
            revertopts['rev'] = revertopts['rev'][0]
            dialog = Confirm('Revert', files, self, 'Revert files to revision ' + revertopts['rev'] + '?')
        else:
            dialog = Confirm('Revert', files, self)
        if dialog.run() == gtk.RESPONSE_YES:
            success, outtext = self._hg_call_wrapper('Revert', dohgrevert)
            if success:
                self.reload_status()

    def _add_clicked(self, toolbutton, data=None):
        add_list = self._relevant_files('?')
        if len(add_list) > 0:
            self._hg_add(add_list)
        else:
            Prompt('Nothing Added', 'No addable files selected', self).run()
        return True


    def _add_file(self, stat, file):
        self._hg_add([file])
        return True


    def _hg_add(self, files):
        # Create new opts, so nothing unintented gets through
        addopts = self.merge_opts(commands.table['^add'][1], ('include', 'exclude'))
        def dohgadd():
            commands.add(self.ui, self.repo, *files, **addopts)
        success, outtext = self._hg_call_wrapper('Add', dohgadd)
        if success:
            self.reload_status()


    def _delete_clicked(self, toolbutton, data=None):
        delete_list = self._relevant_files('?I')
        if len(delete_list) > 0:
            self._delete_files(delete_list)
        else:
            Prompt('Nothing Deleted', 'No deletable files selected', self).run()
        return True


    def _delete_file(self, stat, file):
        self._delete_files([file])


    def _delete_files(self, files):
        dialog = Confirm('Delete', files, self)
        if dialog.run() == gtk.RESPONSE_YES :
            errors = ''
            for file in files:
                try: 
                    os.unlink(self.repo.wjoin(file))
                except Exception, inst:
                    errors += str(inst) + '\n\n'

            if errors:
                errors = errors.replace('\\\\', '\\')
                if len(errors) > 500:
                    errors = errors[:errors.find('\n',500)] + '\n...'
                Prompt('Delete Errors', errors, self).run()

            self.reload_status()
        return True


    def _ignore_file(self, stat, file):
        ignore = open(self.repo.wjoin('.hgignore'), 'a')
        try:
            try:
                ignore.write('glob:' + util.pconvert(file) + '\n')
            except IOError:
                Prompt('Ignore Failed', 'Could not update .hgignore', self).run()
        finally:
            ignore.close()
        self.reload_status()
        return True


    def _sel_desel_clicked(self, toolbutton, state):
        for entry in self.model : entry[0] = state
        return True


    def _relevant_files(self, stats):
        return [item[2] for item in self.model if item[0] and item[1] in stats]


    def _context_menu_act(self, menuitem, handler):
        selection = self.tree.get_selection()
        assert(selection.count_selected_rows() == 1)

        list, paths = selection.get_selected_rows() 
        path = paths[0]
        handler(list[path][1], list[path][2])
        return True


    def _tree_button_press(self, widget, event) :
        # Set the flag to ignore the next activation when the shift/control keys are
        # pressed. This avoids activations with multiple rows selected.
        if event.type == gtk.gdk._2BUTTON_PRESS and  \
          (event.state & (gtk.gdk.SHIFT_MASK | gtk.gdk.CONTROL_MASK)):
            self._ignore_next_act = True
        else:
            self._ignore_next_act = False
        return False


    def _tree_button_release(self, widget, event) :
        if event.button == 3 and not (event.state & (gtk.gdk.SHIFT_MASK | gtk.gdk.CONTROL_MASK)):
            self._tree_popup_menu(widget, event.button, event.time)
        return False


    def _tree_popup_menu(self, widget, button=0, time=0) :
        selection = self.tree.get_selection()
        if selection.count_selected_rows() != 1:
            return False

        list, paths = selection.get_selected_rows() 
        path = paths[0]
        menu = self._menus[list[path][1]]
        menu.popup(None, None, None, button, time)
        return True


    def _tree_key_press(self, tree, event):
        if event.keyval == 32:
            def toggler(list, path, iter):
                list[path][0] = not list[path][0]

            selection = self.tree.get_selection()
            selection.selected_foreach(toggler)
            return True
        return False


    def _tree_row_act(self, tree, path, column) :
        """Default action is the first entry in the context menu
        """
        # Ignore activations (like double click) on the first column,
        # and ignore all actions if the flag is set
        if column.get_sort_column_id() == 0 or self._ignore_next_act:
            self._ignore_next_act = False
            return True

        selection = self.tree.get_selection()
        if selection.count_selected_rows() != 1:
            return False

        list, paths = selection.get_selected_rows() 
        path = paths[0]
        menu = self._menus[list[path][1]]
        menu.get_children()[0].activate()
        return True


class GCommit(GStatus):
    """GTK+ based dialog for displaying repository status and committing changes.

    Also provides related operations like add, delete, remove, revert, refresh,
    ignore, diff, and edit.
    """

    ### Overrides of base class methods ###

    def parse_opts(self):
        GStatus.parse_opts(self)

        # Need an entry, because extdiff code expects it
        if not self.test_opt('rev'):
            self.opts['rev'] = ''

        if self.test_opt('message'):
            buffer = gtk.TextBuffer()
            buffer.set_text(self.opts['message'])
            self.text.set_buffer(buffer)

        if self.test_opt('logfile'):
            buffer = gtk.TextBuffer()
            buffer.set_text('Comment will be read from file ' + self.opts['logfile'])
            self.text.set_buffer(buffer)
            self.text.set_sensitive(False)


    def get_title(self):
        return os.path.basename(self.repo.root) + ' commit ' + ' '.join(self.pats) + ' ' + self.opts['user'] + ' ' + self.opts['date']


    def auto_check(self):
        if self.test_opt('check'):
            for entry in self.model : 
                if entry[1] in 'MAR':
                    entry[0] = True


    def save_settings(self):
        settings = GStatus.save_settings(self)
        settings['gcommit'] = self._vpaned.get_position()
        return settings


    def load_settings(self, settings):
        GStatus.load_settings(self, settings)
        if settings:
            self._setting_vpos = settings['gcommit']
        else:
            self._setting_vpos = -1


    def get_tbbuttons(self):
        tbbuttons = GStatus.get_tbbuttons(self)
        tbbuttons.insert(2, self.make_toolbutton(gtk.STOCK_OK, '_commit', self._commit_clicked))
        return tbbuttons


    def get_body(self):
        status_body = GStatus.get_body(self)

        frame = gtk.Frame()
        frame.set_shadow_type(gtk.SHADOW_ETCHED_IN)
        scroller = gtk.ScrolledWindow()
        scroller.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        frame.add(scroller)
        
        self.text = gtk.TextView()
        self.text.set_wrap_mode(gtk.WRAP_WORD)
        self.text.modify_font(pango.FontDescription(self.fontcomment))
        scroller.add(self.text)
        
        self._vpaned = gtk.VPaned()
        self._vpaned.add1(frame)
        self._vpaned.add2(status_body)
        self._vpaned.set_position(self._setting_vpos)
        return self._vpaned


    def get_menu_info(self):
        """Returns menu info in this order: merge, addrem, unknown, clean, ignored, deleted
        """
        merge, addrem, unknown, clean, ignored, deleted  = GStatus.get_menu_info(self)
        return (merge + (('_commit', self._commit_file),),
                addrem + (('_commit', self._commit_file),),
                unknown + (('_commit', self._commit_file),),
                clean,
                ignored,
                deleted + (('_commit', self._commit_file),))


    def should_live(self, widget=None, event=None):
        # If there are more than a few character typed into the commit
        # message, ask if the exit should continue.
        live = False
        if self.text.get_buffer().get_char_count() > 10:
            dialog = Confirm('Exit', [], self, 'Discard commit message and exit?')
            if dialog.run() == gtk.RESPONSE_NO:
                live = True
        return live

    ### End of overridable methods ###


    def _commit_clicked(self, toolbutton, data=None):
        if not self._ready_message():
            return True

        commitable = 'MAR'
        addremove_list = self._relevant_files('?!')
        if len(addremove_list) and self._should_addremove(addremove_list):
            commitable += '?!'

        commit_list = self._relevant_files(commitable)
        if len(commit_list) > 0:
            self._hg_commit(commit_list)
        else:
            Prompt('Nothing Commited', 'No committable files selected', self).run()
        return True


    def _commit_file(self, stat, file):
        if self._ready_message():
            if stat not in '?!' or self._should_addremove([file]):
                self._hg_commit([file])
        return True


    def _should_addremove(self, files):
        if self.test_opt('addremove'):
            return True
        else:
            response = Confirm('Add/Remove', files, self).run() 
            if response == gtk.RESPONSE_YES:
                # This will stay set for further commits (meaning no more prompts). Problem?
                self.opts['addremove'] = True
                return True
        return False


    def _ready_message(self):
        begin, end = self.text.get_buffer().get_bounds()
        message = self.text.get_buffer().get_text(begin, end) 
        if not self.test_opt('logfile') and not message:
            Prompt('Nothing Commited', 'Please enter commit message', self).run()
            self.text.grab_focus()
            return False
        else:
            if not self.test_opt('logfile'):
                self.opts['message'] = message
            return True


    def _hg_commit(self, files):
        # In case new commit args are added in the future, merge the hg defaults
        commitopts = self.merge_opts(commands.table['^commit|ci'][1], [name[1] for name in cmdtable['gcommit|gci'][1]])
        def dohgcommit():
            commands.commit(self.ui, self.repo, *files, **commitopts)
        success, outtext = self._hg_call_wrapper('Commit', dohgcommit)
        if success:
            self.text.set_buffer(gtk.TextBuffer())
            self.reload_status()


class NativeSaveFileDialogWrapper:
    """Wrap the windows file dialog, or display default gtk dialog if that isn't available"""
    def __init__(self, InitialDir = None, Title = "Save File", Filter = {"All files": "*.*"}, FilterIndex = 1):
        import os.path
        if InitialDir == None:
            InitialDir = os.path.expanduser("~")
        self.InitialDir = InitialDir
        self.Title = Title
        self.Filter = Filter
        self.FilterIndex = FilterIndex

    def run(self):
        """run the file dialog, either return a file name, or False if the user aborted the dialog"""
        try:
            import win32gui
            if self.tortoiseHgIsInstalled(): #as of 20071021, the file dialog will hang if the tortoiseHg shell extension is installed. I have no clue why, yet - Tyberius Prime
                   return self.runCompatible()
            else:
                    return self.runWindows()
        except ImportError:
            return self.runCompatible()

    def tortoiseHgIsInstalled(self):
        import _winreg
        try:
            hkey = _winreg.OpenKey(_winreg.HKEY_LOCAL_MACHINE,r"Software\Microsoft\Windows\CurrentVersion\Explorer\ShellIconOverlayIdentifiers\Changed")
            if hkey:
                cls = _winreg.QueryValue(hkey,"")
                return cls == "{102C6A24-5F38-4186-B64A-237011809FAB}"
        except WindowsError: #reg key not found
            pass
        return False

    def runWindows(self):
        import win32gui, win32con, os
        filter = ""
        for name, pattern in self.Filter.items():
            filter += name + "\0" + pattern + "\0"
        customfilter = "\0"

        fname, customfilter, flags=win32gui.GetSaveFileNameW(
            InitialDir=self.InitialDir,
            Flags=win32con.OFN_EXPLORER,
            File='', DefExt='py',
            Title=self.Title,
            Filter="",
            CustomFilter="",
            FilterIndex=1)
        if fname:
            return fname
        else:
           return False

    def runCompatible(self):
        file_save =gtk.FileChooserDialog(self.Title,None,
                gtk.FILE_CHOOSER_ACTION_SAVE
                , (gtk.STOCK_CANCEL
                    , gtk.RESPONSE_CANCEL
                    , gtk.STOCK_SAVE
                    , gtk.RESPONSE_OK))
        file_save.set_default_response(gtk.RESPONSE_OK)
        file_save.set_current_folder(self.InitialDir)
        for name, pattern in self.Filter.items():
            fi = gtk.FileFilter()
            fi.set_name(name)
            fi.add_pattern(pattern)
            file_save.add_filter(fi)
        if file_save.run() == gtk.RESPONSE_OK:
            result = file_save.get_filename();
        else:
            result = False
        file_save.destroy()
        return result



def findrepo():
    p = os.getcwd()
    while not os.path.isdir(os.path.join(p, '.hg')):
        oldp, p = p, os.path.dirname(p)
        if p == oldp:
            return None
    return p

if __name__ == '__main__':
    u = ui.ui()
    u.updateopts(debug=False, traceback=False)
    repo = hg.repository(u, findrepo())
    gstatus(u, repo, all=False, clean=False, ignored=False, modified=True,
           added=True, removed=True, deleted=True, unknown=True, rev=[],
           exclude=[], include=[], debug=True,
           verbose=True )
#   logparams = {'follow_first': None, 'style': '', 'include': [], 'verbose': True,
#               'only_merges': None, 'keyword': [], 'rev': [], 'copies': None, 'template': '',
#               'patch': None, 'limit': 20, 'no_merges': None, 'exclude': [], 'date': '',
#               'follow': None, 'removed': None, 'prune': [], 'verbose':True }
#    glog(u, repo, **logparams )

