if [ "$IPV6" == "y" ]; then
   OPTS="$OPTS --enable-IPV6"
fi &&

# Fix a simple Samba API name change; not using patch because of a single line
# See "http://websvn.samba.org/cgi-bin/viewcvs.cgi/branches/SAMBA_3_0_RELEASE/source/include/libsmbclient.h?rev=8329&r1=6369&r2=8329"
sedit 's|smb_context->close\>|smb_context->close_fn|g' modules/smb-method.c &&

default_build
