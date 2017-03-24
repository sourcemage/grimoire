source $GRIMOIRE/KDE5_FUNCTIONS &&
cd $SOURCE_DIRECTORY                            &&

local  BUILD_SUBDIRECTORY                       &&

for  BUILD_SUBDIRECTORY  in  $SPELL*
do
  if  [  -d  $BUILD_SUBDIRECTORY  ]
  then
    message  "${MESSAGE_COLOR}Building $BUILD_SUBDIRECTORY${DEFAULT_COLOR}"  &&
    cd $BUILD_SUBDIRECTORY &&
    kde5_build &&
    cd $SOURCE_DIRECTORY
  fi
done
