if    [  "$( installed_version db  |  cut  -c1  )"  ==  "4"  ]
then  sedit  "s/db-3/db-4/g"  configure
      sedit  "s/db-3/db-4/g"  configure.in
fi

OPTS="$OPTS --disable-gtk-doc"

default_build
