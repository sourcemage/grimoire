OPTS+=" -DBUILD_SHARED_LIBS=on" &&
OPTS+=" -DMZ_COMPAT:boolean=${MZ_COMPAT}" &&
# PPMd sources are only available by git clone from 7-Zip during configure
OPTS+=" -DMZ_PPMD=OFF -DMZ_FETCH_LIBS=OFF" &&
cmake_build
