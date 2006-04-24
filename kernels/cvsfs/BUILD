# Fix Bug #1848
for i in `ls ${SCRIPT_DIRECTORY}/*.patch`
do
  patch  -p0  <  $i
done           &&
rm  -rf  init  &&
default_build
