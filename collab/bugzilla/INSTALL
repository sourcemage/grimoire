(

	# kill remnants of CVS, if any
	rm -fr $(find ./ -type d -and -name CVS)        &&
	rm -fr $(find ./ -type f -and -name .cvsignore) &&

	prepare_install &&

	mkdir -p                /usr/share/$SPELL  &&
	cp    -r ./             /usr/share/$SPELL/ &&
	chown -R nobody:nogroup /usr/share/$SPELL  &&

	# it's good to have docs
	if [ -d /usr/doc/$SPELL ]; then
		rm -fr /usr/doc/$SPELL/
	fi                                             &&
	ln -fns /usr/share/$SPELL/docs /usr/doc/$SPELL
    
) >$C_FIFO 2>&1
