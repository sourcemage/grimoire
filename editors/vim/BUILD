#
# First build without the GUI
#
local  OLD_OPTS=$OPTS  &&

OPTS="$GVIM_MULTIBYTE                 \
      --with-features=${VIM_FEATURES} \
      --disable-workshop              \
      --enable-gui=no                 \
      --without-x                     \
      --disable-xim                   \
      --disable-fontset               \
      $GVIM_HANGUL                    \
      $OPTS"                          &&

sedit  '/shUntil\|link shRepeat/{
     /shUntil/N
     /^/i\
     if exists("b:is_kornshell") || exists("b:is_bash")
     p
     /$/i\
     endif
     d
     }' "runtime/syntax/sh.vim"  &&

default_build  &&

#
# Now build the GUI, if it's wanted
#
if  [  "$GVIM_GUI"  !=  "none"  ];  then
  #
  # Backup the non-GUI vim binary for installation later
  #
  mv  src/vim  vim.nox  &&

  #
  # Cleanup the prior build
  #
  make  distclean  &&

  #
  # Now build the GUI and then install
  #
  OPTS="--enable-gui=$GVIM_GUI  \
        $GVIM_MULTIBYTE         \
        $GVIM_SUN               \
        $GVIM_HANGUL            \
        $OLD_OPTS"              &&

  default_build
fi
