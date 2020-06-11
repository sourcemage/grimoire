case "$HOST" in
x86_64-*)    kern=linuxx8664 lisp=lx86cl64 ;;
i[3456]86-*) kern=linuxx8632 lisp=lx86cl32 ;;
*)
  echo "$HOST not supported"
  exit 1
  ;;
esac &&
make -C lisp-kernel/"$kern" \
	CC="$CC" \
	&&
./"$lisp" -n -Q -b -e '(ccl:rebuild-ccl :full t)' -e '(ccl:quit)'
