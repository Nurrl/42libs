# ###
# Defines
# ###
CC		:= gcc

LD		:= gcc
AR		:= ar

RM		:= rm -f
MAKE	:= make
LN		:= cp

MAKEFLAGS \
		:= --no-print-directory

SHELL	:= /bin/bash

# Styles.
_END	:= $(shell echo -ne "\x1b[0m")
_BOLD	:= $(shell echo -ne "\x1b[1m")
_UNDER	:= $(shell echo -ne "\x1b[4m")
_REV	:= $(shell echo -ne "\x1b[7m")

# Colors.
_GREY	:= $(shell echo -ne "\x1b[30m")
_RED	:= $(shell echo -ne "\x1b[31m")
_GREEN	:= $(shell echo -ne "\x1b[32m")
_BLUE	:= $(shell echo -ne "\x1b[34m")
_CYAN	:= $(shell echo -ne "\x1b[36m")
_WHITE	:= $(shell echo -ne "\x1b[37m")

# Inverted, i.e. colored backgrounds.
_IGREY	:= $(shell echo -ne "\x1b[40m")
_IRED	:= $(shell echo -ne "\x1b[41m")
_IGREEN	:= $(shell echo -ne "\x1b[42m")
_IBLUE	:= $(shell echo -ne "\x1b[44m")
_ICYAN	:= $(shell echo -ne "\x1b[46m")
_IWHITE	:= $(shell echo -ne "\x1b[47m")

# Custom format variables.
_BLANK	:= @perl -e \
				"print \"\r\"; print \" \"x$(shell tput cols); print \"\r\""
_HEAD	:= $(shell echo -ne "$(_BOLD)$(PROJECT):$(_END) ")

# Status.
_SUCCS	:= $(shell echo -ne "$(_GREEN)✔$(_END)")
_FAILR	:= $(shell echo -ne "$(_RED)✘$(_END)")

define \n


endef

