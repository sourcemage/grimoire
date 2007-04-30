./configure                                             &&
mkdir -p ${INSTALL_ROOT}/usr/share/yorick               &&
sed -i -r "s:(Y_SITE=).*:\1/usr/share/yorick:" Make.cfg &&
sed -i -r "s:(Y_HOME=).*:\1/usr/share/yorick:" Make.cfg &&
make
