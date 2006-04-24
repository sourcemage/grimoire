# $Id: BUILD,v 1.1 2002/07/29 23:53:53 sergeyli Exp $
(
	rm ./html/mainfile.php                                &&

	prepare_install                                       &&

	mkdir -p      /usr/share/$SPELL                       &&
	cp    -r .    /usr/share/$SPELL/                      &&
#	chmod -R 0777 /usr/share/$SPELL/html/install/         &&
	chmod    0777 /usr/share/$SPELL/html/mainfile.php*    &&
	chmod -R 0755 /usr/share/$SPELL/html/modules/*/cache/ &&

	echo "Please point your apache at /usr/share/$SPELL/html and request install.php."
	echo "You will need to delete /usr/share/$SPELL/html/install.php afterwards."
    
) >$C_FIFO 2>&1
