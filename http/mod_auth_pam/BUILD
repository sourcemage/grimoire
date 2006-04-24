message "${MESSAGE_COLOR}Checking for Apache 2.x${DEFAULT_COLOR}" &&
if  `httpd -v | grep -q "Apache/2\.1"`;  then
  patch -p1 < $SCRIPT_DIRECTORY/aaa.patch
fi  &&

make
