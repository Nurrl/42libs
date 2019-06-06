# Include common stuff
include $(shell dirname $(lastword $(MAKEFILE_LIST)))/core.mk

$(LIBFILES):
	@$(MAKE) -s --directory $(dir $@)

$(NAME): $(LIBFILES) $(OBJS)
	@$(LD) $(OBJS) $(LDFLAGS) -o $(NAME)
	$(_BLANK)
	@echo -n "$(_HEAD)$(_GREEN)✔$(_END) $(NAME)"
ifndef LNKNAME
	@echo
endif
