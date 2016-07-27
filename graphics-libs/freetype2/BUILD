enable_ftoption() {
  sed -r -i "/$1/s;[*/];;g" include/freetype/config/ftoption.h
}

disable_ftoption() {
  sed -r -i "/$1/s;^#define.*;/* & */;" include/freetype/config/ftoption.h
}

if [[ ${FT2_BYTECODE} == "n" ]]; then
  disable_ftoption TT_CONFIG_OPTION_BYTECODE_INTERPRETER
else
  case ${FT2_SUBPIXEL_HINTING} in
      new)
          enable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+2" ;;
      old)
          enable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+1" ;;
     both)
          enable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+\( 1 \| 2 \)" ;;
        *)
          message "${PROBLEM_COLOR}Broken configuration, try cast -r ${SPELL}${DEFAULT_COLOR}" &&
          return 1 ;;
  esac
fi &&

if [[ ${FT2_SUBPIXEL} == "y" ]]; then
  enable_ftoption FT_CONFIG_OPTION_SUBPIXEL_RENDERING
fi &&

OPTS+=" $FREETYPE_OPTS --disable-static" &&
default_build
