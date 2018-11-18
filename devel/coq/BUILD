./configure -prefix ${INSTALL_ROOT}/usr \
            -mandir ${INSTALL_ROOT}/usr/share/man \
	    -camlp5dir ${INSTALL_ROOT}/usr/lib/ocaml/camlp5 \
            -libdir /usr/lib/coq \
            ${OPTS} &&
make_single         &&
CAML_LD_LIBRARY_PATH=$(pwd)/kernel/byterun default_build_make  &&
make_normal
