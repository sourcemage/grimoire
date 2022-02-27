fs=($REFIND_FS) &&
make -j"$MAKE_NJOBS" all_gnuefi \
     FILESYSTEMS_GNUEFI="${fs[@]/%/_gnuefi}" \
     CC="${CC:-cc}"
