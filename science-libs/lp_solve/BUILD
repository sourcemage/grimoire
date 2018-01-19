cd  lpsolve55    &&
sh  ccc          &&
cd  ../lp_solve  &&
# compile this by hand to take advantage of the previously built liblpsolve
# so we don't compile everything three times :)
gcc -I.. -I../bfp -I../bfp/bfp_LUSOL -I../bfp/bfp_LUSOL/LUSOL -I../colamd \
  -I../shared -DYY_NEVER_INTERACTIVE -DPARSER_LP -DINVERSE_ACTIVE=INVERSE_LUSOL \
  -DRoleIsExternalInvEngine $CFLAGS -c lp_solve.c  &&
gcc -o lp_solve lp_solve.o $LDFLAGS -lm -ldl -L../lpsolve55/bin/ux64 -llpsolve55
