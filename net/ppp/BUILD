create_group  ppp  &&

# The following patch is needed on x86-64 to properly detect -lcrypt in /usr/lib64
patch -p1 < "${SCRIPT_DIRECTORY}/ppp-2.4.3-x86-64.diff" &&

sedit  's:net/bpf.h:pcap-bpf.h:'     pppd/demand.c       &&
sedit  's:net/bpf.h:pcap-bpf.h:'     pppd/sys-linux.c    &&
sedit  's:/usr/man:/usr/share/man:'  linux/Makefile.top  &&
if [ "$HAVE_CBCP" == "y" ]; then
  sedit  's:#CBCP=y:CBCP=y:'         pppd/Makefile.linux
fi                                                       &&

default_build
