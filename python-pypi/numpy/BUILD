unset LDFLAGS  &&
if is_depends_enabled numpy atlas; then
    default_build || return 1
else
    ATLAS=None PTATLAS=None BLAS=None LAPACK=None MKL=None default_build || return 1
fi
