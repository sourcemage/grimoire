cp RULES.linux RULES  &&
sedit  "s:XD3D_DIR = .*:XD3D_DIR = $PWD:"                         RULES  &&
sedit  "s:INSTALL_DIR = .*:INSTALL_DIR = $INSTALL_ROOT/usr/bin:"  RULES  &&
sedit  "s:LIBX11 = .*:LIBX11 = $INSTALL_ROOT/usr/X11R6/lib:"      RULES  &&
sedit  "s:LANGUAGE = .*:LANGUAGE = ENGLISH:"                      RULES  &&
sedit  "s:MEMORY_XD3D = .*:MEMORY_XD3D = 256:"                    RULES  &&
sedit  "s:COMPILF = .*:COMPILF = gfortran:"                       RULES  &&
make
