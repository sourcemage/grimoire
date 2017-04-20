for font in *.bdf; do
  bdftopcf "${font}" | gzip -9 > "${font}.pcf.gz"
done
