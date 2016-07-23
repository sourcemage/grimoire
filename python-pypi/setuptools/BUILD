# both versions of python may be present
if is_depends_enabled $SPELL python;then
   python bootstrap.py &&
   default_build_python
fi &&
if is_depends_enabled $SPELL python3;then
   python3 bootstrap.py &&
   default_build_python3
fi
