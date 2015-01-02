cd $SOURCE_DIRECTORY/source &&
# recommended for a system wide install
OPTS+="--disable-renaming --disable-static" &&
CC=gcc CXX=g++ ./configure --prefix=/usr $OPTS &&

# set options as recommended by icu project
sed -i '1 i\
#define U_DISABLE_RENAMING 1\
#define U_CHARSET_IS_UTF8 1\
#define U_USING_ICU_NAMESPACE 0\
#define U_NO_DEFAULT_INCLUDE_UTF_HEADERS 1\
' common/unicode/uconfig.h &&

make

#  these are unused at the moment
#define UNISTR_FROM_CHAR_EXPLICIT explicit\
#define UNISTR_FROM_STRING_EXPLICIT explicit 
