OPTS="$OPTS -f-Benchmark"    &&
OPTS="$OPTS -f-Android"      &&
OPTS="$OPTS -f-AndroidSlice" &&

default_build &&

cd "$SOURCE_DIRECTORY/doc" &&
for mdwn in *.mdwn; do
  progname=$(echo $mdwn | sed -e 's:.mdwn$::')
  section=1
  manpage=$progname.1
  ../Build/mdwn2man $progname $section $mdwn | gzip -9 > $manpage.gz
done
