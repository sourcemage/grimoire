#disable_pic                 &&

if  [ "$MPLAYER2_BRANCH" != "scm" ];  then
  OPTS="$MPLAYER_OPTS $MPLAYER_IVTV $OPTS"
else
  OPTS="$MPLAYER_OPTS $OPTS"
fi  &&

if  [ "$MPLAYER2_BRANCH" == "scm" ];  then
  local PYVER=$(installed_version python3) &&
  sed -i "s:python3:python${PYVER%\.*}:" \
         TOOLS/{file2string,matroska,vdpau_functions}.py
fi &&

CFLAGS= ./configure  --prefix=${INSTALL_ROOT}/usr  \
             --confdir=${TRACK_ROOT}/etc/mplayer   \
             $OPTS  &&

if is_depends_enabled $SPELL openal; then
  make
else
  make_single &&
  make &&
  make_normal
fi
