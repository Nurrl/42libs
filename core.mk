# ###
# I - Global defines
# ###
MODULE	:= $(notdir \
   $(lastword $(filter-out $(lastword $(MAKEFILE_LIST)), $(MAKEFILE_LIST))))

ifndef MODULE
    $(error You cannot include this file alone)
endif

include $(LIBDIR)/defines.mk

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
    $(foreach lib, $(LIBSPATH), $(eval \
    ifeq (0, $(shell test -d "$(lib)/$(INCDIR)"; echo $$?)) ${\n} \
        INCS	+= $(addsuffix /$(INCDIR), $(lib)) ${\n} \
    else ${\n} \
        INCS	+= $(lib) ${\n} \
    endif \
    ))

    # Linker flags
    LDFLAGS		+= $(addprefix -L$(LIBDIR)/, $(LIBS))
    ifneq ($(shell uname -s),Darwin)
        LDFLAGS	+= -Wl,--start-group
    endif
    LDFLAGS		+= $(addprefix -l, $(patsubst lib%, %, $(LIBS)))
    LDFLAGS		+= $(addprefix -l, $(patsubst lib%, %, $(SLIBS)))
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
# III - Targets
# ###
ifeq ($(MODULE), project.mk)
all: $(LIBS) $(NAME) $(LNKNAME)

$(LIBS):
	@$(MAKE) -s --directory $(LIBDIR)/$@
else
all: $(NAME) $(LNKNAME)
endif

ifneq (, $(shell which norminette))
norm:
	@norminette $(NFLAGS) \
		| grep -v 'Not a valid file' | grep -E 'Warning|Error' -B 1 || true

.PHONY: norm
endif

ifdef LNKNAME
$(LNKNAME): $(NAME)
	@$(LN) $(NAME) $(LNKNAME)
	@echo " $(_CYAN)⬅$(_END) $(LNKNAME)"
endif

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPS)
	@[ ! -d $(shell dirname $@) ] && mkdir -p $(shell dirname $@) || true
	@$(CC) $(CFLAGS) -c $< -o $@
	$(_BLANK)
	@echo -n "$(_HEAD)$<"

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
	@echo -n "$(_HEAD)$(_RED)⨯$(_END) exec"
ifdef LNKNAME
	@$(RM) $(LNKNAME)
	@echo -n " $(_RED)⨯$(_END) lnk"
endif
	@echo

fclean: clean eclean

re: fclean all

.PHONY: all clean eclean fclean re

