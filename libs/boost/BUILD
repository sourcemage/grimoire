# Doesn't like Python 2.4 yet
#if  spell_ok  python;  then
#  export  OPTS="${OPTS}  PYTHON_ROOT=/usr"    &&
#  export  OPTS="${OPTS}  PYTHON_VERSION=2.4"
#fi  &&

export CXXFLAGS="$CFLAGS"                 &&

cd  libs/config                           &&
chmod u+x configure                       &&
./configure --prefix=${INSTALL_ROOT}/usr  \
        --sysconfdir=${INSTALL_ROOT}/etc  \
     --localstatedir=${INSTALL_ROOT}/var  \
                     $OPTS                &&
cp  user.hpp  ../../boost/config          &&
cd  ../..                                 &&
bjam  -j $MAKE_NJOBS  \
    "-sBUILD=release <runtime-link>dynamic <threading>single"
