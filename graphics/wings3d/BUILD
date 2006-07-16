local WINGS3D_PATH               &&

if spell_ok xorg-server; then
   sedit 's:GL_LIBS = -lGLU -lGL:GL_LIBS = -L/usr/lib -lGLU -lGL:' plugins_src/accel/Makefile
else
   sedit 's:GL_LIBS = -lGLU -lGL:GL_LIBS = -L/usr/X11R6/lib -lGLU -lGL:' plugins_src/accel/Makefile
fi  &&

export ESDL_PATH=/usr/lib/esdl   &&
WINGS3D_PATH=/usr/lib/wings      &&
make_single                      &&
make
