export  QTDIR=${QTDIR:-$INSTALL_ROOT/usr}                  &&
export  QMAKESPEC=${QTDIR}/share/qt/mkspecs/linux-g++      &&

for i in fparser dxflib
do
  echo  $i >> /tmp/test                                    &&
  cd  $i                                                   &&
  ./configure                                              &&
  make                                                     &&
  cd  ..
done                                                       &&

cd qcadcmd                                                 &&
make prepare                                               &&
cd ..                                                      &&

sedit  s:mtext+=data.text\;:mtext+=data.text.c_str\(\)\;:  \
       qcadlib/src/filters/rs_filterdxf.cpp                &&

for i in qcadlib qcadcmd qcadactions qcadguiqt qcad
do
  cd  $i                                                   &&
  make                                                     &&
  cd  ..
done

