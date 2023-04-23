OPTS+=' smack=false tests=unsafe split-usr=true' &&
OPTS+=' split-bin=true' &&
OPTS+=' rootlibdir=/lib' &&
OPTS+=' default-hierarchy=hybrid' &&
OPTS+=' nobody-group=nogroup' &&

case $(get_spell_provider ${SPELL} INIT) in
          openrc) OPTS+=' cgroup-controller=openrc'  ;;
  simpleinit-msb) OPTS+=' cgroup-controller=telinit' ;;
         systemd) OPTS+=' cgroup-controller=systemd' ;;
               *) OPTS+=' cgroup-controller=none'    ;;
esac &&
default_build
