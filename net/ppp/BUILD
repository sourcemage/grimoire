create_group  ppp  &&

sedit  's:net/bpf.h:pcap-bpf.h:'     pppd/demand.c       &&
sedit  's:net/bpf.h:pcap-bpf.h:'     pppd/sys-linux.c    &&
sedit  's:/usr/man:/usr/share/man:'  linux/Makefile.top  &&
if [ "$HAVE_CBCP" == "y" ]; then
  sedit  's:#CBCP=y:CBCP=y:'         pppd/Makefile.linux
fi                                                       &&

default_build
