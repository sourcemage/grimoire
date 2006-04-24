  cp    makeconfig           makeconfig.original
  sed  "s:/usr/local:/usr:"  makeconfig.original  >  makeconfig

  ./makeconfig  CONFIG=/etc          \
                INETDCONF=/dev/null  \
                SERVICES=/dev/null   &&
  make
