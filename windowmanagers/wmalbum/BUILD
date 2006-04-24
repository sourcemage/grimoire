if [ ! -z $PAT_FRONT -o -z $PAT_BACK  ] ; then

  RPAT_FRONT=""
  RPAT_BACK=""
  if [ "$PAT_FRONT" != "--none--" ] ; then RPAT_FRONT="$PAT_FRONT" ; fi
  if [ "$PAT_BACK" != "--none--" ] ; then RPAT_BACK="$PAT_BACK" ; fi
  sedit "s/^\(#define DEFAULT_PREPEND_REGEX\) \"{{F,f}ront,}\"\$/\1 \"$RPAT_FRONT\"/" $SOURCE_DIRECTORY/wmalbum/wmalbum.c
  sedit "s/^\(#define DEFAULT_APPEND_REGEX\) \"\.{jpeg,gif,jpg}\"$/\1 \"$RPAT_BACK\"/" $SOURCE_DIRECTORY/wmalbum/wmalbum.c

fi && 
default_build
