# You'd set DUMA_OPTIONS in the GNUmakefile for special setup.
# For a system-wide install, it makes most sense to keep the
# default feature set.
make_single && # The makefile is not parallel-safe.
make -f GNUmakefile CC="${CC:-gcc}" CXX="${CXX:-g++}" OS=linux
