# Include common stuff
include $(shell dirname $(lastword $(MAKEFILE_LIST)))/core.mk

ARFLAGS	:= rcs

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(_BLANK)
	@echo -n "$(_HEAD)$(_GREEN)✔$(_END) $(NAME)"
ifndef LNKNAME
	@echo
endif
