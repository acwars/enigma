VERCMD  ?= git describe --tags 2> /dev/null
VERSION := $(shell $(VERCMD) || cat VERSION)

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -DVERSION=\"$(VERSION)\"
CFLAGS   += -std=c99 -pedantic -Wall -Wextra -DJSMN_STRICT
LDFLAGS  ?=
LDLIBS    = $(LDFLAGS) -lm -lxcb -lxcb-util -lxcb-keysyms -lxcb-icccm -lxcb-ewmh -lxcb-randr -lxcb-xinerama -lxcb-shape

PREFIX    ?= /usr/local
BINPREFIX ?= $(PREFIX)/bin
MANPREFIX ?= $(PREFIX)/share/man
DOCPREFIX ?= $(PREFIX)/share/doc/enigma
BASHCPL   ?= $(PREFIX)/share/bash-completion/completions

XSESSIONS ?= $(PREFIX)/share/xsessions

WM_SRC   = enigma.c helpers.c geometry.c jsmn.c settings.c monitor.c desktop.c tree.c stack.c history.c \
	 events.c pointer.c window.c messages.c parse.c query.c restore.c rule.c ewmh.c subscribe.c
WM_OBJ  := $(WM_SRC:.c=.o)
CLI_SRC  = enigmac.c helpers.c
CLI_OBJ := $(CLI_SRC:.c=.o)

all: enigma enigmac

debug: CFLAGS += -O0 -g
debug: enigma enigmac

VPATH=src

include Sourcedeps

$(WM_OBJ) $(CLI_OBJ): Makefile

enigma: $(WM_OBJ)

enigmac: $(CLI_OBJ)

install:
	mkdir -p "$(DESTDIR)$(BINPREFIX)"
	cp -pf enigma "$(DESTDIR)$(BINPREFIX)"
	cp -pf enigmac "$(DESTDIR)$(BINPREFIX)"
	mkdir -p "$(DESTDIR)$(MANPREFIX)"/man1
	cp -p doc/enigma.1 "$(DESTDIR)$(MANPREFIX)"/man1
	cp -Pp doc/enigmac.1 "$(DESTDIR)$(MANPREFIX)"/man1
	mkdir -p "$(DESTDIR)$(BASHCPL)"
	cp -p examples/bash_completion "$(DESTDIR)$(BASHCPL)"/enigmac
	mkdir -p "$(DESTDIR)$(DOCPREFIX)"/examples
	cp -pr examples/* "$(DESTDIR)$(DOCPREFIX)"/examples
	mkdir -p "$(DESTDIR)$(XSESSIONS)"
	cp -p examples/enigma.desktop "$(DESTDIR)$(XSESSIONS)"

uninstall:
	rm -f "$(DESTDIR)$(BINPREFIX)"/enigma
	rm -f "$(DESTDIR)$(BINPREFIX)"/enigmac
	rm -f "$(DESTDIR)$(MANPREFIX)"/man1/enigma.1
	rm -f "$(DESTDIR)$(MANPREFIX)"/man1/enigmac.1
	rm -f "$(DESTDIR)$(BASHCPL)"/enigmac
	rm -rf "$(DESTDIR)$(DOCPREFIX)"
	rm -f "$(DESTDIR)$(XSESSIONS)"/enigma.desktop

doc:
	a2x -v -d manpage -f manpage -a revnumber=$(VERSION) doc/enigma.1.asciidoc

clean:
	rm -f $(WM_OBJ) $(CLI_OBJ) enigma enigmac

.PHONY: all debug install uninstall doc clean
