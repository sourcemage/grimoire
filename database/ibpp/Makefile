###############################################################################
#
#	File    : $Id: Makefile,v 1.37.2.5 2005/09/27 09:46:42 epocman Exp $
#	Subject : IBPP - Multi-Platform GNU Makefile
#
###############################################################################
#
#	The contents of this file are subject to the Mozilla Public License
#	Version 1.0 (the "License"); you may not use this file except in
#	compliance with the License. You may obtain a copy of the License at
#	http://www.mozilla.org/MPL/
#
#	Software distributed under the License is distributed on an "AS IS"
#	basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
#	License for the specific language governing rights and limitations
#	under the License.
#
#	The Original Code is "IBPP 0.9" and all its associated documentation.
#
#	The Initial Developer of the Original Code is T.I.P. Group S.A.
#	Portions created by T.I.P. Group S.A. are
#	Copyright (C) 2000 T.I.P Group S.A.
#	All Rights Reserved.
#
#	Contributor(s):	Matt Hortman, initial developer of this Makefile
#	                Olivier Mascia, maintainer
#
###############################################################################
#
#	COMMENTS
#
#	* Tabulations should be set every four characters when editing this file.
#	* For instructions, read the howtobuild.txt file. Some comments in this
#	* file can also be usefull if you have to tweak the build procedure to
#	* your needs.
#
COMPILER=IBPP_GCC	# The only compiler supported on linux anyway

# set target directories
ROOTDIR:=$(shell pwd)
ROOTDIR:=$(subst \,/,$(ROOTDIR))
TARGETDIR=../build
DS=

# *************************************************
# Source Files
# *************************************************

HDRS =	ibpp.h
#HDRS +=	_internals.h
#HDRS +=	_msvcwarnings.h

SRCS =	_dpb.cpp
SRCS +=	_ibs.cpp
SRCS +=	_rb.cpp
SRCS +=	_spb.cpp
SRCS +=	_tpb.cpp
SRCS +=	array.cpp
SRCS +=	blob.cpp
SRCS +=	database.cpp
SRCS +=	dbkey.cpp
SRCS +=	events.cpp
SRCS +=	exception.cpp
SRCS +=	_ibpp.cpp
SRCS +=	service.cpp
SRCS += row.cpp
SRCS +=	statement.cpp
SRCS +=	transaction.cpp
SRCS +=	user.cpp

SRCS +=	date.cpp
SRCS +=	time.cpp

# *************************************************
# Conditional Compile Options
# *************************************************


# building on linux (any flavour, I suppose)
CXXOUTPUT =	-o
CXXFLAGS =-DIBPP_LINUX -DIBPP_GCC -fPIC -I./ -I./fbheaders $(CFLAGS)
	#
	# change -lfbclient by -lgds if building with Firebird 1.x or InterBase
	# -lfbclient (or -lgds) is for Firebird 1.5 SS and higher
	# -lfbembed is for Firebird 1.5 CS and higher
	#
LIBS+=-lfbclient -lcrypt -lm -ldl -lpthread # dependancies for shared library
	#
	TARGETS =	$(TARGETDIR)/libibpp$(DS).a \
				$(TARGETDIR)/libibpp$(DS).so 

# *************************************************
# Derived Definitions
# *************************************************

# make an object from each source file
OBJS:=$(addprefix $(TARGETDIR)/,$(addsuffix .o,$(basename $(SRCS))))

# *************************************************
# Build Rules
# *************************************************


#don't delete when generated indirectly
.SECONDARY: $(HDRS) $(SRCS)

all:  $(TARGETS)

# disable internal rules
%.o: %.cpp

# our own specific compilation rule
$(TARGETDIR)/%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) $(CXXOUTPUT)$@ -c $<


$(TARGETDIR)/libibpp$(DS).a: $(OBJS)
	@rm -f $@
	@ar rv $@ $^
	@ranlib $@

$(TARGETDIR)/libibpp$(DS).so: $(OBJS)
	$(CXX) $^ $(LDFLAGS) -shared -o $@ $(LIBS)

