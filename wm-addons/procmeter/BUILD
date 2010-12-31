make_single &&
make procmeter3-lcd &&
make procmeter3-log &&
if is_depends_enabled $SPELL libxaw; then
    make procmeter3-xaw || return 1
fi &&
if is_depends_enabled $SPELL gtk+; then
    make procmeter3-gtk1 || return 1
fi &&
if is_depends_enabled $SPELL gtk+2; then
    make procmeter3-gtk2 || return 1
fi &&
make_normal
