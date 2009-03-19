setup_file=$(detect_setup_file)
runhaskell $setup_file configure --prefix=${INSTALL_ROOT}/usr --constraint="base < 4" &&
runhaskell $setup_file build
