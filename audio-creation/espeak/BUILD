cd src                                                  &&
sedit "s: -O2::" Makefile                               &&
sedit "s:-lportaudio:-lportaudio ${LDFLAGS}:" Makefile  &&
sedit "s:/usr:${INSTALL_ROOT}/usr:g" speak.cpp          &&
make
