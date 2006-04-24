export TMAKEPATH=/usr/share/tmake/lib/linux-g++             &&
cd src                                                      &&
tmake xxdiff.pro > Makefile                                 &&
sedit  "s/-O2/$CFLAGS/" Makefile                            &&
sedit  's/$(QTDIR)\/include/\/usr\/include\/qt/'  Makefile  &&
sedit  's/$(QTDIR)\/lib/\/usr\/lib\/qt/'  Makefile          &&
sedit  's/$(QTDIR)\/bin\/moc/\/usr\/bin\/moc/'  Makefile    &&
sedit  's/$(QTDIR)\/bin\/uic/\/usr\/bin\/uic/'  Makefile    &&
make
