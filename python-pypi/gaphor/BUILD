# rm -rf is fix for this version, and should be probably removed in next
rm -rf data/plugins/pynsource/pynsource-1.4a &&

# also should have been fixed in next version
patch -p0 < $SCRIPT_DIRECTORY/msgfmt.patch  &&

python setup.py build
