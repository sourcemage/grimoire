# $Id: BUILD,v 1.1 2002/07/30 18:55:22 sergeyli Exp $
(
	cp ./apache.conf             ./apache.conf.default &&
	cp ./php/config_default.pinc ./php/config.pinc     &&

	prepare_install                                    &&

	mkdir -p   /usr/share/$SPELL                       &&
	cp    -R . /usr/share/$SPELL/
    
) > $C_FIFO 2>&1 && (

	echo "Please point your apache at /usr/share/$SPELL/php"
	echo "Edit or update /usr/share/$SPELL/php/config.pinc"
	echo "as well as /usr/share/$SPELL/apache.conf"
	echo "Access document scheme.php to create/update database schema"
	echo "and then remove scheme.php and update.php from the file system"

)
