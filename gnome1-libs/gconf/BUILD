sedit  "s:db3/db.h:db.h:"  configure     &&
sedit  "s:db3/db.h:db.h:"  configure.in  &&
  
if    [  "$( installed_version db  |  cut  -c1  )"  ==  "4"  ]
then
  sedit  "s/3.3/4.0/g"  configure     &&
  sedit  "s/3.3/4.0/g"  configure.in
fi  &&

./configure  --prefix=/usr      \
             --sysconfdir=/etc  &&
make_single                     &&
make                            &&
make_normal
