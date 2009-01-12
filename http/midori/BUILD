if [[ $MIDORI_WAF == n ]]; then
  default_build
else
  ./waf --prefix=${INSTALL_ROOT}/usr configure &&
  ./waf build
fi
