(

  ./configure  --prefix=/usr         \
               --sysconfdir=/etc     \
               --localstatedir=/var  \
               $OPTS                 &&
  make                               &&
  prepare_install                    &&
  make    install-strip              &&

  case  $CONFIGS  in
    y|Y) make installconf ;;
  esac

) > $C_FIFO 2>&1


