sed -i '30i#include <unicode/utf8.h>' \
    Source/WebCore/platform/text/TextCodecUTF8.h &&
sed -i '30i#include <unicode/utf16.h>' \
     Source/WTF/wtf/text/StringBuilder.h &&
sed -i '26i#include <unicode/utf16.h>' \
    Source/WTF/wtf/text/StringImpl.h &&
sed -i '29i#include <unicode/utf16.h>' \
    Source/WTF/wtf/unicode/UTF8.h &&

sed -i 's;fltk-config13;fltk-config;g' \
    Source/WebKit/gtk/Makefile &&

CXXFLAGS="$CXXFLAGS -DNDEBUG" &&

make -C Source/WTF/wtf &&
make -C Source/JavaScriptCore gen &&
make -C Source/JavaScriptCore &&
make -C Source/WebCore &&
make -C Source/WebKit/fltk
