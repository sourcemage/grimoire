readonly  -a  LABELS=([0]="Main" [1]="Extra")

#  target directory is embedded in this patch along with options
#  to use cvsgraph and enscript and other changes (see HISTORY)
#  this patch also makes sure configuration is not overwritten
patch  -p1  <  $SCRIPT_DIRECTORY/$SPELL.patch  &&

message  "Looking for existing CVS repositories (this may take some time)"  &&
CVS_CONFIG=/CVSROOT/config,v
REPOSITORY_LIST=""
COUNT=0
for  REPOSITORY_PATH  in  `find  /  -mount  -path  *$CVS_CONFIG`;  do
  [  -n  "$REPOSITORY_LIST"  ]  &&  REPOSITORY_LIST="$REPOSITORY_LIST,"
  REPOSITORY_LIST="$REPOSITORY_LIST ${LABELS[$COUNT]:-CVS$COUNT} : ${REPOSITORY_PATH%${CVS_CONFIG}}"
  COUNT=$(($COUNT + 1))
done  &&

if  [  -n  "$REPOSITORY_LIST"  ];  then
  pushd  cgi  >  /dev/null
  sed  "s/cvs_roots\W*=.*$/cvs_roots =${REPOSITORY_LIST//\//\\/}/"  \
       <  viewcvs.conf.dist                                         \
       >  viewcvs.conf.dist.1
  sed "s/default_root\W*=.*$/default_root = ${LABELS[0]}/"        \
      <  viewcvs.conf.dist.1                                       \
      >  viewcvs.conf.dist
  rm -f viewcvs.conf.dist.1
  popd      > /dev/null
fi  ||  true
