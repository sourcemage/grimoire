(
  if  [ ! -d  /usr/share/babytrans  ];  then
    mkdir /usr/share/babytrans
  fi                                                                      &&
  if  [ ! -d  /usr/lib/babytrans  ];  then
    mkdir /usr/lib/babytrans
  fi                                                                      &&


  unpack $SOURCE ${MD5[0]}                                                &&
  gunzip -c $SOURCE_CACHE/dictionary.gz | sed s/usr[/]local/usr/ > dict   &&
  cp dict /usr/share/babytrans/dictionary                                 &&

  unpack $SOURCE2 ${MD5[1]}                                               &&
  gunzip -c $SOURCE_CACHE/english.dic.gz > english.dic                    &&
  cp english.dic /usr/lib/babytrans/                                      &&

  for LANGUAGE in $LANGUAGES
  do
    LANGUAGE=` echo $LANGUAGE | sed s/\"//g `                             &&
    gunzip -c $SOURCE_CACHE/Engto$LANGUAGE.dic.gz > Engto${LANGUAGE}.dic  &&
    cp Engto${LANGUAGE}.dic /usr/lib/babytrans/
  done

) > $C_FIFO 2>&1
