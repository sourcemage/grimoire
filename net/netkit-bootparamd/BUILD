sedit "s:PREFIX/man:PREFIX/share/man:" configure  &&
sedit  's!=rpcgen!=rpcgen -Y /usr/bin!'  rpc.bootparamd/Makefile  &&

./configure  --prefix=$INSTALL_ROOT/usr  $OPTS	&&
make 
