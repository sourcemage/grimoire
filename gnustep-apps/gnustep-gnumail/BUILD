make_single                  &&
default_build                &&
if [[ "$GMEMO" == "y" ]];
then
    pushd Bundles/Emoticon   &&
    default_build            &&
    popd
fi                           &&

if [[ "$GMFAC" == "y" ]];
then
    pushd Bundles/Face       &&
    default_build            &&
    popd
fi                           &&


if [[ "$GMPGP" == "y" ]];
then
    pushd Bundles/PGP        &&
    default_build            &&
    popd
fi                           &&
make_normal
