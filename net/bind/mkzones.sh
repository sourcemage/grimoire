[ -z "$1" ] &&
cat <<EOF && exit 1
This utility regenerates your zones.conf file and makes a szones-gen.conf file to put on your other slaves. as szones.conf (SMGL) or in named.conf
Pass the master servers for the slave file as ip-dotted ip addresses like so:
$0 10.10.1.20 10.10.1.30
for slaves that master to the above two IP addresses.  If you aren't going to use slaves, just make up a random IP and ignore the generated file.
EOF
cd /etc/bind/m
for j in *.zone; do
i="${j%%.zone}"
cat <<EOF
zone "$i" {
	type master;
	file "m/$j";
};

EOF
done > /etc/bind/zones.conf
for j in `ls *.rev | grep -vFx localhost.rev`; do
i="${j%%.zone}"
cat <<EOF
zone "$i" {
	type master;
	file "m/$j";
};

EOF
done >> /etc/bind/zones.conf
MASTERS=
for ip in $*; do
  MASTERS="$MASTERS		$ip;
"
done
for j in *.zone; do
i="${j%%.zone}"
cat <<EOF
zone "$i" {
	type slave;
	file "s/$j.bak";
	masters {
$MASTERS	};
};

EOF
done > /etc/bind/szones-gen.conf
for j in `ls *.rev | grep -vFx localhost.rev`; do
i="${j%%.zone}"
cat <<EOF
zone "$i" {
	type slave;
	file "s/$j.bak";
	masters {
$MASTERS	};
};

EOF
done >> /etc/bind/szones-gen.conf
