cd $SOURCE_DIRECTORY &&
message "Compiling UPX" && 
cd src &&
sedit "s!# configuration section!UCLDIR=${SOURCE_DIRECTORY2}!" Makefile &&
sedit "s/CC_COMPILE    = \$(CC)  \$(CCARCH)  \$(DEFS) \$(EXTRA_DEFS) \$(INCLUDES) \$(EXTRA_INCLUDES) \$(CFLAGS)   \$(EXTRA_CFLAGS)   \$(CFLAGS_OUTPUT)   -c \$(CC_SRC)/CC_COMPILE    = \$(CC)  \$(DEFS) \$(EXTRA_DEFS) \$(INCLUDES) \$(EXTRA_INCLUDES) ${CFLAGS}  \$(EXTRA_CFLAGS)   \$(CFLAGS_OUTPUT)   -c \$(CC_SRC)/" Makefile.bld &&
sedit "s/CXX_COMPILE   = \$(CXX) \$(CXXARCH) \$(DEFS) \$(EXTRA_DEFS) \$(INCLUDES) \$(EXTRA_INCLUDES) \$(CXXFLAGS) \$(EXTRA_CXXFLAGS) \$(CXXFLAGS_OUTPUT) -c \$(CXX_SRC)/CXX_COMPILE   = \$(CXX) \$(DEFS) \$(EXTRA_DEFS) \$(INCLUDES) \$(EXTRA_INCLUDES) ${CXXFLAGS} \$(EXTRA_CXXFLAGS) \$(CXXFLAGS_OUTPUT) -c \$(CXX_SRC)/" Makefile.bld &&
make target=linux &&

if spell_installed perl; then
   message "Compiling documentation" && 
   cd $SOURCE_DIRECTORY && cd doc &&
   make
fi

#Deleting useless SOURCE_DIRECTORY2
rm -rf ${SOURCE_DIRECTORY2}
