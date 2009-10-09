#!/usr/bin/env ruby
require 'mkmf'
   $LDFLAGS = $LDFLAGS + " -lfbclient -lpthread"
   $CFLAGS  = $CFLAGS + " -DOS_UNIX"

# Make sure the firebird stuff is included.
dir_config("firebird", "/opt/firebird/include", "/opt/firebird/lib")

# Generate the Makefile.
#create_makefile("fireruby")
create_makefile("fr_lib")
