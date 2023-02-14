for f in ${SPELL}-${VERSION}/*/*.bdf; do
  bdftopcf $f | gzip -9 > ${f%%.bdf}.pcf.gz
done
