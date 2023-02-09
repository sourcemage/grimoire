NAME    := copyevent

CFLAGS   += -Wall -Wextra
LDLIBS   := -lX11 -lXfixes

PREFIX    ?= /usr/local
BINPREFIX ?= $(PREFIX)/bin

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

all: $(NAME)

debug: CFLAGS += -O0 -g
debug: $(NAME)

$(OBJ): Makefile

$(NAME): $(OBJ)

install:
	mkdir -p "$(DESTDIR)$(BINPREFIX)"
	cp -p $(NAME) "$(DESTDIR)$(BINPREFIX)"

uninstall:
	rm -f "$(DESTDIR)$(BINPREFIX)/$(NAME)"

clean:
	rm -f $(OBJ) $(NAME)

.PHONY: all debug install uninstall clean
