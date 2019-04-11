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
ifndef PROJS
    $(error Variable PROJS is not set (list of subprojects).)
endif

NAME	?= multi

$(NAME): all
all: $(PROJS)

eclean:
	@$(foreach proj, $(PROJS), make -C $(SUBDIR)/${PATHS.${proj}} $@${\n})

clean:
	@$(foreach proj, $(PROJS), make -C $(SUBDIR)/${PATHS.${proj}} $@${\n})

fclean: eclean clean

re: fclean all

$(PROJS):
	@make -C $(SUBDIR)/${PATHS.${@}} all

.PHONY: all $(NAME) $(PROJS) eclean clean fclean re
