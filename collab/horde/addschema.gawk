{
	if ($0 ~ /^include\W+.*\.schema/)
		previous_include = 1
	else {
		if (previous_include == 1 && include_complete != 1) {
			print "include		/etc/openldap/schema/horde.schema"
			include_complete = 1
		}
		previous_include=0
	}
	print
}
