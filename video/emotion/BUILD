mkdir  config
echo  /usr  >  config/PREFIX
echo  /usr  >  config/QTDIR

sedit  "s:qtdir+'/include':qtdir+'/include/qt':"  SConstruct.py  &&
sedit  "s/install: all/install:/"     Makefile  &&
sedit  "s/cp uninstall_emotion.*$//"  Makefile  &&
make
