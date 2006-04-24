(
	prepare_install                                    &&

	mkdir -p   /usr/share/$SPELL                       &&
	cp    -R . /usr/share/$SPELL/
    
) > $C_FIFO 2>&1 && (

	echo "Please point your apache at /usr/share/$SPELL"
	echo "Edit or update /usr/share/$SPELL/config_inc.php"
	echo "Access document scheme.php to create/update database schema"
	echo "and then remove scheme.php and update.php from the file system"

)
