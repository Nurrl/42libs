# ###
# I - Global defines
# ###
MODULE	:= $(notdir \
   $(lastword $(filter-out $(lastword $(MAKEFILE_LIST)), $(MAKEFILE_LIST))))

ifndef MODULE
    $(error You cannot include this file alone)
endif

CC		:= gcc

LD		:= gcc
AR		:= ar

RM		:= rm -f
MAKE	:= make --no-print-directory

SHELL	:= /bin/bash

define \n


endef

# ###
# II - Variables and flags
# ###

# Check if variables are undefined
ifndef PROJECT
    $(error Variable PROJECT is not set.)
endif
ifndef NAME
    $(error Variable NAME (executable path) is not set.)
endif

ifndef SRCDIR
    $(error Variable SRCDIR (where are your sources ?) is not set.)
endif
ifndef OBJDIR
    $(error Variable OBJDIR (where are your objs ?) is not set.)
endif
ifndef INCDIR
    $(error Variable INCDIR (where are your headers ?) is not set.)
endif

ifndef SRCS
    $(error Variable SRCS (what are the names of your sources in '$(SRCDIR)/' ?) is not set.)
endif

SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INCS	+= $(INCDIR)

DEPS	+= Makefile $(shell find $(INCDIR) -type f -name *.h)

ifdef LIBS
    ifndef LIBDIR
        $(error Please specify LIBDIR to search libs.)
    endif

    # Check for directory presence
    $(foreach lib, $(LIBS), \
        $(if $(filter 1, $(shell test -d "$(LIBDIR)/$(lib)"; echo $$?)), \
            $(error Sorry but '$(LIBDIR)/$(lib)/' does not exist.)) \
    )

    LIBSPATH	:= $(addprefix $(LIBDIR)/, $(LIBS))
    $(foreach lib, $(LIBS), $(eval LIBFILES += $(LIBDIR)/$(lib)/$(lib).a))

    # Includes for external libaries
    INCS		+= $(addsuffix /$(INCDIR), $(LIBSPATH))
    LDFLAGS		+= $(addprefix -L$(LIBDIR)/, $(LIBS))
    ifneq ($(shell uname -s),Darwin)
        LDFLAGS	+= -Wl,--start-group
    endif
    LDFLAGS		+= $(addprefix -l, $(patsubst lib%, %, $(LIBS)))
    ifneq ($(shell uname -s),Darwin)
        LDFLAGS	+= -Wl,--end-group
    endif
endif

CFLAGS	?= -Wall -Wextra -Werror
ifeq ($(DEBUG), 1)
	CFLAGS	:= $(filter-out -Werror,$(CFLAGS)) -g3
	MKVARS	+= DEBUG=$(DEBUG)
else
	CFLAGS	+= -Ofast
endif
CFLAGS	+= $(addprefix -I, $(INCS))
MAKE	+= $(MKVARS)

# ###
# III - Formats and output
# ###
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
_HEAD	:= $(shell echo -ne " $(_BOLD)$(_UNDER)▲$(PROJECT)▼$(_END) ")

# ###
# VI - Targets
# ###
ifeq ($(MODULE), project.mk)
all: $(LIBS) $(NAME)

$(LIBS):
	@$(MAKE) -s --directory $(LIBDIR)/$@
else
all: $(NAME)
endif

ifneq (, $(shell which norminette))
norm:
	@norminette $(NFLAGS) \
		| grep -v 'Not a valid file' | grep -E 'Warning|Error' -B 1 || true
endif

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPS)
	@[ ! -d $(shell dirname $@) ] && mkdir -p $(shell dirname $@) || true
	@$(CC) $(CFLAGS) -c $< -o $@
	$(_BLANK)
	@echo -n "$(_HEAD)$< $(_GREEN)➤$(_END) $@"

clean:
ifeq ($(MODULE), project.mk)
	@$(foreach path, $(LIBSPATH), $(MAKE) -C $(path) clean${\n})
endif
	@$(RM) $(OBJS)
	@echo "$(_HEAD)$(_RED)⨯$(_END) objs"

eclean:
ifeq ($(MODULE), project.mk)
	@$(foreach path, $(LIBSPATH), $(MAKE) -C $(path) eclean${\n})
endif
	@$(RM) $(NAME)
	@echo "$(_HEAD)$(_RED)⨯$(_END) exec"

fclean: clean eclean

re: fclean all

.PHONY: all clean eclean fclean re

