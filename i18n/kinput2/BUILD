sed -i "s/#define UseSj3//" Kinput2.conf       &&

if [[ $DICT_SERVER != canna ]]; then
    sed -i "s/#define UseCanna//" Kinput2.conf                       &&
    sed -i "s/\/\* #define UseWnn \*\//#define UseWnn/" Kinput2.conf &&
    sed -i "s/^WNN/XCOMM _WNN/" Kinput2.conf                         &&
    sed -i "s/XCOMM WNN/WNN/" Kinput2.conf
fi                                             &&

sed -i "s/\/usr\/X11R6/\/usr/" Kinput2.conf    &&
sed -i "s/\/usr\/local/\/usr/" Kinput2.conf    &&
sed -i "s/\/usr\/canna/\/usr/" Kinput2.conf    &&
sed -i "s/\/usr/${INSTALL_ROOT//\//\\\/}\/usr/" Kinput2.conf &&

xmkmf           &&
make Makefiles  &&
make
