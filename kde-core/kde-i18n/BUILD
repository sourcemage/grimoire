local  BUILD_SUBDIRECTORY  &&

for  BUILD_SUBDIRECTORY  in  $SOURCE_DIRECTORY/$SPELL*
do
  if  [  -d  $BUILD_SUBDIRECTORY  ]
  then
    message  "${MESSAGE_COLOR}Building $BUILD_SUBDIRECTORY${DEFAULT_COLOR}"  &&
    cd $BUILD_SUBDIRECTORY                                                   &&
    source  $SECTION_DIRECTORY/KDE_BUILD                                   &&
    cd ..
  fi
done
