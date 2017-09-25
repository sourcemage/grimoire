export CLANG_INSTALL_DIR=/usr &&
CXXFLAGS="${CXXFLAGS//-DPIC}" &&
# Installed rust might be broken because of system llvm
# (happend on updgrade to 5.0.0). Better always start
# fresh. Alternative: Don't use system llvm.
OPTS+=" --disable-local-rust" &&
./configure --prefix="$INSTALL_ROOT"/usr --enable-extended --disable-docs --enable-llvm-link-shared $OPTS &&

sed -i "/BOOTSTRAP.*doc/d" Makefile &&

make
