(

	readonly ALPHABET="1234567890abcdefghijklmnopqrstuvxyz"

	config_dir="/etc/usermin"
	var_dir="/var/log/usermin"
	perl="`which perl`"
	host="`hostname`"
#	generate port number between 2048 and (16384 - 1)
	port=$((RANDOM % (16384 - 2048) + 2048))
	os_type="debian-linux"
	os_version="3.0"
	real_os_type="Source Mage GNU/Linux"
	real_os_version="1.0"
	atboot=1
	ssl=0
	spell_ok Net-SSLeay && ssl=1
	login="admin"
	password=
	for (( C = 0; C < 8; ++C )) do
		password="${password}${ALPHABET:RANDOM % 36:1}"
	done
	export config_dir var_dir perl host port            \
		os_type os_version real_os_type real_os_version \
		atboot ssl login password

	echo "Default password: $password"

	prepare_install                &&
	mkdir -p     /usr/share/usermin &&
	cp    -dfR . /usr/share/usermin &&
	cd           /usr/share/usermin &&

	./setup.sh

) >$C_FIFO 2>&1
