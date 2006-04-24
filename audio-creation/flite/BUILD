if [ "$VOICE_16" == "y" ]; then
  sedit  "s/\@FL_VOX\@/cmu_us_kal16/" config/config.in
fi &&
sedit "s/#include <string.h>/#include <string.h>\n#define const/g" tools/find_sts_main.c
default_build

