for i in SConstruct linux-settings.py; do
  sedit "s:/usr/local:/usr:" $i
done &&

#prevent .sconsign files from being created everywhere.
sedit "/SConscript/a\
SConsignFile()" SConstruct &&

scons
