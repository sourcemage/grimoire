(

  sedit "s/-O2//" Makefile &&

  make &&
  prepare_install &&
  mkdir -p /usr/lib/gkrellm/plugins &&
  install -m 644 gkrellweather.so /usr/lib/gkrellm/plugins/ &&
  install -m 755 GrabWeather /usr/bin/

) > $C_FIFO 2>&1
