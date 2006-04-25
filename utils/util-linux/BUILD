OPTS="$OPTS --build=${BUILD}" &
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

patch -p1 < $SCRIPT_DIRECTORY/util-linux-2.12p-cramfs-1.patch &&

sedit  "s/HAVE_SLN=no/HAVE_SLN=yes/"            MCONFIG  &&
sedit  "s/# ADD_RAW=yes/ADD_RAW=yes/"           MCONFIG  &&
sedit  "s/\$(OPT)//"                            MCONFIG  &&
# Stupid `make install` doesn't honor --prefix
sedit  "s:/dev:${TRACK_ROOT}/dev:"            MCONFIG  &&
sedit  "s:/etc:${TRACK_ROOT}/etc:"            MCONFIG  &&
# Stupid people who use TABs in their files...
sedit  "s:      /sbin: ${TRACK_ROOT}/sbin:"   MCONFIG  &&
sedit  "s:/usr:${TRACK_ROOT}/usr:g"           MCONFIG  &&
sedit  "s:BIN_DIR=        /bin: BIN_DIR=${TRACK_ROOT}/bin:"    MCONFIG  &&
sedit  "s:=       /var/:=       ${TRACK_ROOT}/var:g" MCONFIG  &&

#ORIGINAL Below############################################
#sedit  "s:	/sbin: ${INSTALL_ROOT}/sbin:"   MCONFIG  &&
#sedit  "s:/usr:${INSTALL_ROOT}/usr:g"           MCONFIG  &&
#sedit  "s: /bin: ${INSTALL_ROOT}/bin:"          MCONFIG  &&
#sedit  "s:/var:${INSTALL_ROOT}/var:g"           MCONFIG  &&
############################################################

if [ "$SELINUX" == "y" ]; then
  sedit  "s/HAVE_SELINUX=no/HAVE_SELINUX=yes/" MCONFIG &&
  message "${MESSAGE_COLOR} SELINUX is  enabled ${DEFAULT_COLOR}"
fi &&

disable_pic  &&

./configure --prefix=${TRACK_ROOT}/usr  \
        --sysconfdir=${TRACK_ROOT}/etc  \
     --localstatedir=${TRACK_ROOT}/var  \
            --mandir=${TRACK_ROOT}/usr/share/man   \
           --infodir=${TRACK_ROOT}/usr/share/info  \
                     $OPTS                 &&
make &&

if    spell_ok      util-linux-crypto
  then  dispel  --nosustain  util-linux-crypto
fi
