  ###################################
  ##  Build the selected packages  ##
  ###################################

  make                                                          &&

  if [ $INCLUDE_CALLBACK=="y" ] ; then
     cd   callback/                                             &&
     make                                                       &&
     cd   ../
  fi                                                            &&

  if [ $INCLUDE_DIALOG=="y" ] ; then
     cd   frontends/dialog/                                     &&
     make                                                       &&
     cd   ../../
  fi                                                            &&

  if [ $INCLUDE_VIEWFAX=="y" ] ; then
     cd   frontends/X11/viewfax*/                               &&
     xmkmf                                                      &&
     make                                                       &&
     make depend                                                &&
     cd   ../../../
  fi                                                            &&

  if [ $INCLUDE_TOOLS=="y" ] ; then
     cd   tools/                                                &&
     make                                                       &&
     cd   ../
  fi                                                            &&

  if [ $INCLUDE_VGETTY=="y" ] ; then
     make vgetty
  fi
