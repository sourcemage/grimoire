export KDEPIMDIR = $(shell pwd)

export KDEPIM_VERSION=$(shell sed -e 's/.*\"\([0-9]*\.[0-9]*\.[0-9]*\).*/\1/' < ../version)
export KDEDIR=/usr
export KDE_DEV_DIR=/usr
all: 
	cd ../kde2file/caldump;qmake;make
	cd ../kde2file/abdump;qmake;make

install:	
	mkdir -p /opt/kdepimpi
	mkdir -p /opt/kde3/share/applnk/PIM-pi
#	rm -rf /opt/kdepimpi/*
#	rm -f /usr/lib/libmicro*
#	rm -fr /opt/kde3/share/applnk/PIM-pi/*
	cp -r ../bin/* /opt/kdepimpi/
	cp --no-dereference ../bin/libmicro* /usr/lib/
	rm -rf /opt/kdepimpi/libmicro*
	rm -rf /usr/lib/libmicrokabc_*
	cp --no-dereference ../bin/libmicrokabc_* /opt/kdepimpi/
	cd /opt/kdepimpi; rm -dfR CVS
	cd /opt/kdepimpi/kdepim; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/pwmanager; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/pwmanager/icons22; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/pwmanager/icons16; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/korganizer; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/korganizer/icons16; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/korganizer/iconsmini; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/korganizer/icons16; rm -dfR .xvpics
	cd /opt/kdepimpi/kdepim/korganizer/iconsmini; rm -dfR .xvpics
	cd /opt/kdepimpi/kdepim/korganizer; rm -dfR .xvpics
	cd /opt/kdepimpi/kdepim/kaddressbook; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/kaddressbook/icons22; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/kaddressbook/icons16; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/kopiemail/icons22; rm -dfR CVS
	cd /opt/kdepimpi/kdepim/kopiemail; rm -dfR CVS
	cd /opt/kdepimpi/kdepim; rm -f Make*
	cp -r PIM-pi/* /opt/kde3/share/applnk/PIM-pi/
	cd /opt/kde3/share/applnk/PIM-pi; rm -fr CVS
#adding KPhone/Pi and KTimeTracker/Pi to the distribution
#	cp -fr /home/polo/eigene/apps/* /opt/kdepimpi/
dist: 
	cd rpm;rpmbuild -bb kdepim_rpm
