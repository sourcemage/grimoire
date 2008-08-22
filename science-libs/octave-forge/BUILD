for subdir in */*; do
   tar xzf $subdir
   subdir=${subdir#*/} &&
  cd ${subdir%.tar.gz} &&
#  default_build &&
make
  cd -
done 
