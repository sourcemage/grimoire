if  [  "$GTK2" ==  "n"  -a  "$GTK"  ==  "n"  ]
then
  OPTS="$OPTS  --disable-gtk"
else
  #
  # Need this or else if you ever said 'n' to use gtk+|gtk+2
  # you will never get gtk+|gtk+2 even with `cast -r -c nessus-core`
  #
  OPTS=""
fi  &&

echo  OPTS = $OPTS
sedit  "s/\$localstatedir\/nessus\/CA/\/etc\/ssl\/nessus\/private/"  nessus-mkcert.in  &&
sedit  "s/\$sharedstatedir\/nessus\/CA/\/etc\/ssl\/nessus\/certs/"   nessus-mkcert.in  &&

default_build
