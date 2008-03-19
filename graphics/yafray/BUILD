# going to /usr
sed -i "s:/usr/local:/usr:" SConstruct linux-settings.py &&
sed -i "s:prefix+\"/etc\":\"/etc\":" linux-settings.py &&

# prevent .sconsign files from being created everywhere
sed -i "/SConscript/a\
SConsignFile()" SConstruct &&

scons
