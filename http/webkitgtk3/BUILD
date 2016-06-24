OPTS="$WEBKIT_OPTS $OPTS" &&
sed -i '30i#include <unicode/utf8.h>' \
    Source/WebCore/platform/text/TextCodecUTF8.h \
    Source/WebCore/platform/text/hyphen/HyphenationLibHyphen.cpp \
    Source/JavaScriptCore/runtime/JSGlobalObjectFunctions.cpp &&
sed -i '30i#include <unicode/utf16.h>' \
    Source/WTF/wtf/text/StringBuilder.h &&
sed -i '26i#include <unicode/utf16.h>' \
    Source/WTF/wtf/text/StringImpl.h &&
sed -i '29i#include <unicode/utf16.h>' \
    Source/WTF/wtf/unicode/UTF8.h &&
cmake_build
