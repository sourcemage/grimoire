# $Id: BUILD,v 1.1 2002/07/30 03:12:14 sergeyli Exp $
(
	cp ./pmi.conf ./pmi.conf.default &&

	prepare_install                  &&

	mkdir -p   /usr/share/$SPELL     &&
	cp    -r . /usr/share/$SPELL/
    
) > $C_FIFO 2>&1 && (

	echo "Please point your apache at /usr/share/$SPELL/htdocs"
	echo "Edit or update /usr/share/$SPELL/pmi.conf"

)
