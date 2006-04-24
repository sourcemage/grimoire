__ARCH=$(echo "$CFLAGS" | sed 's|^.*-march=\(\w\+\).*$|\1|') &&
OPTS="$OPTS --cpu=$__ARCH intl man" &&

# although they are not using auto* tools, this works
default_build
