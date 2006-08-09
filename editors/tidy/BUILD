sh build/gnuauto/setup.sh &&
default_build             &&

if [[ "${TIDY_MAN_PAGES}" == "y" ]]
then doxygen -u htmldoc/doxygen.cfg && doxygen htmldoc/doxygen.cfg
fi
