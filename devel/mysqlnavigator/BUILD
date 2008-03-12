### bug 4334 adding -DUSE_OLD_FUNCTIONS for newer mysql
sedit "s/CXXFLAGS=\"-O2 -Wall\"/CXXFLAGS=\"-O2 -Wall $CXXFLAGS -DUSE_OLD_FUNCTIONS\"/g" configure  &&
export QTDIR="/usr"                                         &&
### gcc3.3.X multiline string problem
patch -p1 < $SCRIPT_DIRECTORY/mysqlnavigator-gcc3.3.X.patch &&
default_build
