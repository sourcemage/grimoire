#Construct appropriate cmake option
for WIN in $KCM_WIN;do
  for ACC in $KCM_ACC;do
    OPTS+=" -DBUILD_KCM_${ACC^^}_${WIN^^}=ON"
  done
done &&
message opts=$OPTS
default_build
