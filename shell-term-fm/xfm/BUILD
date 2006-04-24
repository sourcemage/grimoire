patch -p0 << EOF
--- Imake.options       Thu Nov 22 10:55:09 2001
+++ Imake.options       Thu Nov 22 10:55:32 2001
@@ -29,7 +29,7 @@
    option also causes some Xaw3d-specific resources to be included in the
    appdefaults file. */
 
-#define XAW3D
+#undef XAW3D
 
 XAWINCDIR = -I/usr/X11R6/include/X11/Xaw3d
 XAWLIBDIR = -L/usr/X11R6/lib
EOF

invoke_gcc &&
xmkmf  -a  &&
make 
