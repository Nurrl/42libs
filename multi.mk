# ###
# Multi-project building
# ###

include $(LIBDIR)/defines.mk

# ###
# Variables check
# ###

# Check if variables are undefined
ifndef SUBDIR
    $(error Variable SUBDIR is not set (dir containaing the subprojects).)
endif
ifndef SUBS
    $(error Variable SUBS is not set (list of subprojects).)
endif

all: $(SUBS)

eclean:
	@$(foreach path, $(SUBS), make -C $(SUBDIR)/$(path) $@${\n})

clean:
	@$(foreach path, $(SUBS), make -C $(SUBDIR)/$(path) $@${\n})

fclean: eclean clean

re: fclean all

$(SUBS):
	@$(foreach path, $(SUBS), make -C $(SUBDIR)/$(path) all${\n})

.PHONY: all $(SUBS) eclean clean fclean re
