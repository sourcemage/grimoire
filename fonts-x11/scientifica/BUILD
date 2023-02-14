for f in bdf/*.bdf; do
  bdftopcf $f | gzip -9 > ${f%%.bdf}.pcf.gz
done
