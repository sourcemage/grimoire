# the project is pure C++, but gen.py consumes both CFLAGS and CXXFLAGS
unset CFLAGS &&

CXXFLAGS="${CXXFLAGS/-Werror=format-security/}" \
python3 build/gen.py \
	--no-last-commit-position \
	--no-static-libstdc++ \
	--no-strip \
	--allow-warnings &&

if is_depends_enabled "$SPELL" samurai; then
  samu -C out gn
else
  ninja -C out gn
fi
