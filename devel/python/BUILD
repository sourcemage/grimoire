export OPT="$CFLAGS"
export OPTS="$OPTS --enable-shared"
sedit "s/\['ndbm'\]/\['ndbm', 'gdbm_compat'\]/g" setup.py &&

# The following file from kdebindings has a syntax error that
# makes Python compilation fail
local  PYTHON_VERSION=`echo $VERSION|cut -d. -f1,2`
if [ -f  /usr/lib/python${PYTHON_VERSION}/pydcop.py ];  then
  mkdir  $SOURCE_DIRECTORY/spell-tmp                     &&
  mv  /usr/lib/python${PYTHON_VERSION}/pydcop.py  \
      $SOURCE_DIRECTORY/spell-tmp
fi  &&

default_build
