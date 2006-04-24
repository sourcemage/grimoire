patch -p1 < $SCRIPT_DIRECTORY/steghide-0.5.1-gcc34.patch  &&
sedit  's:$(LIBTOOL) --mode=link::'  src/Makefile.in      &&
default_build 
