  disable_pic
  HC="$CFLAGS"

  if    [ "$I586"   == "on" ];  then  TP="i586" HC="$HC -DHAVE_MMX"
  elif  [ "$I686"   == "on" ];  then  TP="i686" HC="$HC -DHAVE_MMX2 -DHAVE_SSE"
  elif  [ "$K6"     == "on" ];  then  TP="k6"   HC="$HC -DHAVE_MMX"

  elif  [ "$ATHLON" == "on" ];  then  TP="athlon" HC="$HC -DHAVE_MMX2 -DHAVE_SSE -DHAVE_3DNOWEX"
  fi


  if spell_ok gpm ; then
    UM="y"
  else
    UM="n"
  fi

  echo "UM=$UM"
  # Something changed in the way sorcery saves the architecture
  # Going to use the 'uname' call to figure out the architecture for now
  # Fixes Bug #936
  TP=`uname -m`
  sedit  "s/TARGET_OS=unix/TARGET_OS=linux/"            makefile  &&
  sedit  "s/TARGET_PLATFORM=i386/TARGET_PLATFORM=$TP/"  makefile  &&
  sedit  "s/HOST_CFLAGS=/HOST_CFLAGS=$HC/"              makefile  &&
  sedit  "s/USE_MOUSE=n/USE_MOUSE=$UM/"                 makefile  &&
  sedit  "s/\/usr\/local/\/usr/"  biewlib/sysdep/generic/unix/os_dep.c  &&

#  invoke_gcc &&
  make
