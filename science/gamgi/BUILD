cd src &&
rm make_local &&

# Adding header paths
echo "PATH_X_H = -I/usr/X11R6/include" >> make_local &&
echo "PATH_GLIB_H = -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include" >> make_local &&
echo "PATH_GTK_H = -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include" >> make_local &&
echo "PATH_CAIRO_H = -I/usr/include/cairo" >> make_local &&
echo "PATH_PANGO_H = -I/usr/include/pango-1.0" >> make_local &&
echo "PATH_ATK_H = -I/usr/include/atk-1.0" >> make_local &&
echo "PATH_MESA_H = -I/usr/include/GL" >> make_local &&
echo "PATH_GTKGL_H = -I/usr/include/gtkglext-1.0/ -I/usr/lib/gtkglext-1.0/include" >> make_local &&
echo "PATH_EXPAT_H = -I/usr/include" >> make_local &&
echo "PATH_FREETYPE_H = -I/usr/include/freetype2" >> make_local &&

# Adding library paths
echo "PATH_X_L = -L/usr/X11R6/lib" >> make_local &&
echo "PATH_GLIB_L = -L/usr/lib/glib" >> make_local &&
echo "PATH_GTK_L = -L/usr/lib" >> make_local &&
echo "PATH_ATK_L = -L/usr/lib" >> make_local &&
echo "PATH_CAIRO_L = -L/usr/lib" >> make_local &&
echo "PATH_PANGO_L = -L/usr/lib" >> make_local &&
echo "PATH_MESA_L = -L/usr/lib" >> make_local &&
echo "PATH_GTKGL_L = -L/usr/lib" >> make_local &&
echo "PATH_EXPAT_L = -L/usr/lib" >> make_local &&

make
