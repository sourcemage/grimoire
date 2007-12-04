unset LDFLAGS
unset CFLAGS
if [[ "$XEN_TARGET_X86_PAE" == "y" ]]
then
  make XEN_TARGET_X86_PAE=y xen
else
  make xen
fi
