patch -p0 <$SPELL_DIRECTORY/font.diff       &&
#cd  libImaging                              &&
#  Ignores  $OPTS                           &&
#./configure                                 &&
#make                                        &&
#cd  ..                                      &&
# a fix for some variable scoping problem in thier setup.py
#mv setup.py set1.py                         &&
sed -i '/HAVE_TCLTK = 0/aEXTRA_COMPILE_ARGS = NoneEXTRA_LINK_ARGS = None' setup.py &&
python  setup.py  build_ext -i
