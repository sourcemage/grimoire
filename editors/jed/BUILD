echo "FOO $OPTS BAR"

cp  ${SCRIPT_DIRECTORY}/FILES/jed.rc lib  &&

# src/gpmmouse.c contains an error: function jed_insert_chars was
# replace by jed_insert_nbytes for UTF-8 reasons
sed -i 's/jed_insert_chars/jed_insert_nbytes/g' ${SOURCE_DIRECTORY}/src/gpmmouse.c &&

#check optional depends: optional dependencies do not use the
#$OPTS in configure-script, but require edit of Makefile

./configure  --build=$BUILD             \
       --prefix=/usr                    \
       --sysconfdir=/etc                \
       --localstatedir=/var             &&

#set jed_root to /usr/share/jed
sed -i 's/JED_ROOT\ =\ \/usr\/jed/JED_ROOT\ =\ \/usr\/share\/jed/g' ${SOURCE_DIRECTORY}/src/Makefile &&
       
if echo ${OPTS} | grep -q "useGPM"
then
        sed -i 's/#MOUSEFLAGS/MOUSEFLAGS/g' ${SOURCE_DIRECTORY}/src/Makefile       &&
        sed -i 's/#MOUSELIB/MOUSELIB/g' ${SOURCE_DIRECTORY}/src/Makefile           &&
        sed -i 's/#GPMMOUSEO/GPMMOUSEO/g' ${SOURCE_DIRECTORY}/src/Makefile         &&
        sed -i 's/#OBJGPM/OBJGPM/g' ${SOURCE_DIRECTORY}/src/Makefile
fi

make clean                              &&
make                                    &&
make  getmail &&

if echo ${OPTS} | grep -q "useX"
then
        # enable antialiasing support
        sed -i 's/#XRENDERFONTLIBS/XRENDERFONTLIBS/g' ${SOURCE_DIRECTORY}/src/Makefile  &&
        #sed -i 's/#define\ XJED_HAS_XRENDERFONT\ 0/#define\ XJED_HAS_XRENDERFONT\ 1/g' ${SOURCE_DIRECTORY}/src/jed-feat.h   &&
        make xjed
fi
