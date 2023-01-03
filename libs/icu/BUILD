cd $SOURCE_DIRECTORY/source &&
# recommended for a system wide install
OPTS+="--disable-renaming --disable-static" &&
CC=gcc CXX=g++ ./configure --prefix=/usr $OPTS &&

# for stable API
sed "s/#define U_DISABLE_RENAMING 0/#define U_DISABLE_RENAMING 1/" \
    -i common/unicode/uconfig.h &&

# Fix linking of icudata
sed "s:LDFLAGSICUDT=-nodefaultlibs -nostdlib:LDFLAGSICUDT=:" \
    -i config/mh-linux &&

make

#  these are unused at the moment
#define UNISTR_FROM_CHAR_EXPLICIT explicit\
#define UNISTR_FROM_STRING_EXPLICIT explicit 
