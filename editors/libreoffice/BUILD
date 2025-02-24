# FIXME: port to box2d 3.0
OPTS+=' --without-system-box2d' &&
# Use our own wrappers instead of libreoffice's buildsystem support
OPTS+=' --disable-ccache' &&
# Release build type
OPTS+=' --enable-release-build' &&
# Use system-provided libraries only
OPTS+=' --with-system-libs --disable-fetch-external' &&
# Use system fonts
OPTS+=' --without-fonts' &&
# Read-Only installation
OPTS+=' --disable-extension-update --enable-readonly-installset' &&

CXXFLAGS+=' -DU_USING_ICU_NAMESPACE=1' &&

install -o nobody -d "$CCACHE_DIR" &&
cd "$SOURCE_DIRECTORY.build" &&
# XXX bails out if you try to build as root
chown nobody . &&
export LO_PATH_FOR_BUILD="$PATH" &&
su nobody -s /bin/sh -c "
\"$SOURCE_DIRECTORY\"/configure \
           --prefix=\"$INSTALL_ROOT\"/usr \
       --sysconfdir=\"$INSTALL_ROOT\"/etc \
    --localstatedir=\"$INSTALL_ROOT\"/var \
           --mandir=\"$INSTALL_ROOT\"/usr/share/man \
          --infodir=\"$INSTALL_ROOT\"/usr/share/info \
            --build=\"$BUILD\" \
             --host=\"$HOST\" \
      --with-vendor=\"SourceMage\" \
                    $OPTS $LIBREOFFICE_OPTS &&
gmake -j $((${#DISTCC_HOSTS[*]} * JOBS_PER_HOST + MAKE_NJOBS)) \
      CCACHE_DIR='$CCACHE_DIR'
"
