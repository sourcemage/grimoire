local UDOBIN=$SOURCE_DIRECTORY/Source/udo                   &&

pushd Source                                                &&
make CFLAGS="$CFLAGS -D__LINUX__" -f Makefile.linux         &&
popd                                                        &&

pushd Guide/eng/manual                                      &&
$UDOBIN --man --verbose --force-long -y -D LANG_EN          \
        -o udo.1 manpage.u                                  &&
popd
