###############################################################################
.SUFFIXES: .o .cpp

OBJECTS_FBE=fbexport/ParseArgs.o fbexport/FBExport.o fbexport/cli-main.o
OBJECTS_FBC=fbcopy/args.o fbcopy/fbcopy.o fbcopy/TableDependency.o fbcopy/main.o 

# Compiler & linker flags
COMPILE_FLAGS=-O3 -DIBPP_LINUX -DIBPP_GCC
LINK_FLAGS=-pthread -L/usr/lib -libpp -L/opt/firebird/lib -lfbclient


all:	exe/fbcopy exe/fbexport

exe/fbexport: $(OBJECTS_FBE)
	g++ $(LINK_FLAGS) $(OBJECTS_FBE) -oexe/fbexport

exe/fbcopy: $(OBJECTS_FBC)
	g++ $(LINK_FLAGS) $(OBJECTS_FBC) -oexe/fbcopy


install:
	install exe/fbcopy /usr/bin/fbcopy
	install exe/fbexport /usr/bin/fbexport

.cpp.o:
	g++ -c $(COMPILE_FLAGS) -o $@ $<

#EOF
