export VTK_DATA_ROOT=/usr/share/vtk/VTKData    &&
export VTK_INSTALL_PATH=/usr                   &&
export CMAKE_INSTALL_PREFIX=/usr               &&

cmake .           &&
sedit "s/^CMAKE_INSTALL_PREFIX:PATH=.*$/CMAKE_INSTALL_PREFIX:PATH=\/usr/" CMakeCache.txt  &&
sedit "s/BUILD_SHARED_LIBS\:BOOL=OFF/BUILD_SHARED_LIBS\:BOOL=ON/" CMakeCache.txt          &&
sedit "s/CMAKE_BUILD_TYPE:STRING=/&Release/" CMakeCache.txt                               &&
sedit "s/BUILD_EXAMPLES\:BOOL=OFF/BUILD_EXAMPLES\:BOOL=ON/" CMakeCache.txt                &&
sedit "s/VTK_USE_HYBRID\:BOOL=OFF/VTK_USE_HYBRID\:BOOL=ON/" CMakeCache.txt                &&
sedit "s/CMAKE_CXX_FLAGS_RELEASE\:STRING=-O3/CMAKE_CXX_FLAGS_RELEASE\:STRING=$CFLAGS/" CMakeCache.txt &&

#Use java.
if echo $OPTS| grep -q "with-java" ; then 
  sedit "s/VTK_USE_SYSTEM_ZLIB\:BOOL=OFF/VTK_USE_SYSTEM_ZLIB\:BOOL=ON/" CMakeCache.txt
fi              &&

if echo $OPTS| grep -q "with-python"; then
  sedit "s/Python language.\" OFF/Python language.\" ON/" CMakeLists.txt 
fi              &&

if echo $OPTS| grep -q "with-tcl"; then
  sedit "s/TCL language.\" OFF/TCL language.\" ON/" CMakeLists.txt 
fi              &&

if echo $OPTS| grep -q "with-doxygen" ; then
  sedit "s/BUILD_DOCUMENTATION\:BOOL=OFF/BUILD_DOCUMENTATION\:BOOL=ON/" CMakeCache.txt
fi              &&

#Use the system's expat library.
if echo $OPTS| grep -q "with-expat" ; then
  sedit "s/VTK_USE_SYSTEM_EXPAT\:BOOL=OFF/VTK_USE_SYSTEM_EXPAT\:BOOL=ON/" CMakeCache.txt
fi              &&

#Use the system's jpeg library.
if echo $OPTS| grep -q "with-jpeg" ; then
  sedit "s/VTK_USE_SYSTEM_JPEG\:BOOL=OFF/VTK_USE_SYSTEM_JPEG\:BOOL=ON/" CMakeCache.txt
fi              &&

#Use the system's png library.
if echo $OPTS| grep -q "with-libpng" ; then
  sedit "s/VTK_USE_SYSTEM_PNG\:BOOL=OFF/VTK_USE_SYSTEM_PNG\:BOOL=ON/" CMakeCache.txt
fi              &&

#Use the system's tiff library.
if echo $OPTS| grep -q "with-tiff" ; then
  sedit "s/VTK_USE_SYSTEM_TIFF\:BOOL=OFF/VTK_USE_SYSTEM_TIFF\:BOOL=ON/" CMakeCache.txt
fi              &&

#Use the system's zlib library.
if echo $OPTS| grep -q "with-zlib" ; then 
  sedit "s/VTK_USE_SYSTEM_ZLIB\:BOOL=OFF/VTK_USE_SYSTEM_ZLIB\:BOOL=ON/" CMakeCache.txt
fi              &&

make

# java is a little broken for now
#  if echo $OPTS| grep -q "with-java" ; then
#     if spell_ok j2sdk ; then export JAVA_HOME=/usr/java/j2sdk; 
#     elif spell_ok j2sdk-bin ; then export JAVA_HOME=/usr/lib/j2sdk1.4.1 ; 
#     fi &&
#  sedit "s/Java language.\" OFF/Java language.\" ON/" CMakeLists.txt  &&
#  stupid thing fails first time on purpose ! so don't use && OK !
#  cmake .
#  sedit "s:^JAVA_AWT_INCLUDE_PATH\:PATH=.*$:JAVA_AWT_INCLUDE_PATH\:PATH=$JAVA_HOME\/include:" CMakeCache.txt  &&
#  sedit "s:^JAVA_AWT_LIBRARY\:FILEPATH=.*$:JAVA_AWT_LIBRARY\:FILEPATH=$JAVA_HOME\/jre\/lib\/i386\/libawt.so:" CMakeCache.txt  &&
#  sedit "s:^JAVA_INCLUDE_PATH\:PATH=.*$:JAVA_INCLUDE_PATH\:PATH=$JAVA_HOME\/include:" CMakeCache.txt  &&
#  sedit "s:^JAVA_INCLUDE_PATH2\:PATH=.*$:JAVA_INCLUDE_PATH2\:PATH=$JAVA_HOME\/include\/linux:" CMakeCache.txt  
#  fi              &&

