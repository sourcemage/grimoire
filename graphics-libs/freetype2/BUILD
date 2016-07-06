enable_ftoption() (
  sed -r -i "/$1/s;[*/];;g" include/freetype/config/ftoption.h
)

disable_ftoption() (
  sed -r -i "/$1/s;^#define.*;/* & */;" include/freetype/config/ftoption.h
)

if [[ ${FT2_BYTECODE} == "n" ]]; then
  disable_ftoption TT_CONFIG_OPTION_BYTECODE_INTERPRETER &&
  disable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+2"
else
  if [[ ${FT2_SUBPIXEL_HINTING} == "old" ]]; then
    enable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+1" &&
    disable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+2"
  elif [[ ${FT2_SUBPIXEL_HINTING} == "both" ]]; then
    disable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+2" &&
    enable_ftoption "TT_CONFIG_OPTION_SUBPIXEL_HINTING[ \t]+\( 1 \| 2 \)"
  fi
fi &&

if [[ ${FT2_SUBPIXEL} == "y" ]]; then
  enable_ftoption FT_CONFIG_OPTION_SUBPIXEL_RENDERING
fi &&

OPTS+=" $FREETYPE_OPTS --disable-static" &&
default_build
