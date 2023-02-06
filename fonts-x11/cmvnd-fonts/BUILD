for f in *.bdf spectrum-fonts/*.bdf; do
  bdftopcf $f | gzip -9 > ${f%%.bdf}.pcf.gz
done
