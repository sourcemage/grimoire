autoconf       &&

# make sure libgtkhtml > 3.7.0 is accepted
sedit 's|libgtkhtml-3\.8 = \$GTKHTML_REQUIRED_VERSION|libgtkhtml-3.8 >= \$GTKHTML_REQUIRED_VERSION|g' configure &&

make_single    &&
default_build  &&
make_normal
