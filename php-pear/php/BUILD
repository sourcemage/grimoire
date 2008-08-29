cd "${SOURCE_DIRECTORY}" &&
OPTS="${PHP5_OPTS} ${OPTS}" &&

# If the CGI or FastCGI SAPI (or both) are selected, enable 'force-cgi-redirect'
if list_find "${OPTS}" "--enable-cgi" || list_find "${OPTS}" "--enable-fastcgi"; then
    message "${MESSAGE_COLOR}CGI or FastCGI SAPI enabled, enabling force-cgi-redirect${DEFAULT_COLOR}" &&
    OPTS="--enable-force-cgi-redirect ${OPTS}"
fi &&

# Setup SSL IMAP if desired
if list_find "${OPTS}" "--with-imap"; then
    # Setup SSL IMAP if desired
    local CCLIENT=$(get_spell_provider $SPELL C-CLIENT) &&

    if [[ ! -z "${CCLIENT}" ]]; then
        if is_depends_enabled $CCLIENT openssl; then
            message "${MESSAGE_COLOR}Enabling SSL for the IMAP extension${DEFAULT_COLOR}" &&
            OPTS="--with-imap-ssl ${OPTS}"
        fi
    fi
fi &&

case "${PHP5_APACHE}" in
    handler)
        if httpd -v | grep -q "Apache/2\."; then
            message "${MESSAGE_COLOR}Configuring for Apache 2.x${DEFAULT_COLOR}" &&
            OPTS="--with-apxs2 ${OPTS}"
        else
            message "${MESSAGE_COLOR}Configuring for Apache 1.x${DEFAULT_COLOR}" &&
            OPTS="--with-apxs ${OPTS}"
        fi
    ;;

    filter)
        OPTS="--with-apxs2filter ${OPTS}"
    ;;
esac &&

#Check for xorg or xserver and pass location of xpm
if [ "$PHP5_X11LIBS" == "y" ]; then
  OPTS="$OPTS --with-xpm-dir=/usr"
fi &&

# Check to see if internal GD requested
if [[ "${PHP5_GD}" == "internal" ]]; then
    OPTS="--with-gd --enable-gd-native-ttf ${OPTS}"
fi &&

OPTS="   --with-exec-dir=${INSTALL_ROOT}/usr/bin \
 --with-config-file-path=${INSTALL_ROOT}/etc \
             --with-pear=${INSTALL_ROOT}/usr/share/pear \
                --enable-cli \
               --disable-rpath \
                --enable-bcmath \
         --enable-inline-optimization \
           --with-layout=GNU \
                   ${OPTS}" &&
default_build &&

# safety precaution against earlier PHP installations removing httpd.conf
pushd "${INSTALL_LOGS}" &>/dev/null &&
local log &&
for log in ${SPELL}-*; do
    if [[ -f "${log}" ]]; then
        sedit 's|.*/httpd\.conf.*||g' "${log}"
    fi
done &&
popd &>/dev/null
