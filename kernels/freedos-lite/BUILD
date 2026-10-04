export WATCOM=/opt/watcom &&
kernel="$SOURCE_DIRECTORY"/SOURCE/KERNEL &&
freecom="$SOURCE_DIRECTORY"/SOURCE/FREECOM &&
tree="$SOURCE_DIRECTORY"/tree &&
make -C "$kernel" all &&
(cd "$freecom" && LNG=english sh build.sh wc) &&
bindir="$tree"/freedos/bin &&
install -Dt "$tree" -m644 \
    "$kernel"/bin/kernel.sys &&
install -Dt "$tree/freedos/bin" -m644 \
    "$kernel"/bin/country.sys \
    "$kernel"/bin/setver.sys \
    "$freecom"/command.com &&
<<-"!">"$tree"/fdconfig.sys sed 's@$@\r@' &&
	COUNTRY=001,858:\\FREEDOS\\BIN\\COUNTRY.SYS
	LASTDRIVE=Z
	BUFFERS=20
	FILES=40
	SHELL=\\FREEDOS\\BIN\\COMMAND.COM \\FREEDOS\\BIN /E:2048 /P=\\FDAUTO.BAT
!
<<-"!">"$tree"/fdauto.bat sed 's@$@\r@' &&
	@echo off
	set PATH=%%CD%%\\FREEDOS\\BIN;%%CD%%
	set DIRCMD=/P /OGN /Y
	prompt $p$g
!
find "$tree" -exec touch -d "@$SOURCE_DATE_EPOCH" {} +
