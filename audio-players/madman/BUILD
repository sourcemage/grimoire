sedit 's:/include:/include/qt:' SConstruct &&
#sedit 's:moc_prefs_dialog\.cc:designer/moc_prefs\.cc:' ui/prefs_dialog.cpp &&
#sedit 's:moc_auto_tag\.cc:designer/moc_auto_tag\.cc:' ui/auto_tag.cpp &&
cd $SOURCE_DIRECTORY/ui &&
moc prefs_dialog.cpp -o moc_prefs_dialog.cc &&
moc auto_tag.cpp -o moc_auto_tag.cc &&
cd $SOURCE_DIRECTORY &&
scons add_c_include_dirs="/usr/include/qt"
