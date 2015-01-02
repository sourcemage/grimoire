CFLAGS="${CFLAGS//-ffast-math}"     &&
CXXFLAGS="${CXXFLAGS//-ffast-math}" &&

OPTS+=" -DBUILD_SHARED_LIBS=ON -DWTK_USE_HYBRID=ON" &&

# Building examples fails on VTK 6.1.0
#OPTS+=' -DBUILD_EXAMPLES=ON'

# Java is a little broken for now
# if echo $OPTS | grep -q VTK_WRAP_JAVA=ON; then
#   if [ -z "$JAVA_HOME" -a -f /etc/profile.d/java.sh ]; then
#     . /etc/profile.d/java.sh
#   fi &&
#   OPTS+=" -DJAVA_INCLUDE_PATH=$JAVA_HOME/include"
#   OPTS+=" -DJAVA_INCLUDE_PATH2=$JAVA_HOME/include/linux"
#   OPTS+=" -DJAVA_AWT_INCLUDE_PATH=$JAVA_HOME/include"
#   OPTS+=" -DJAVA_AWT_LIBRARY=$JAVA_HOME/jre/lib/i386/libawt.so"
# fi

cmake_build
