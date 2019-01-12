# Include common stuff
include $(shell dirname $(lastword $(MAKEFILE_LIST)))/core.mk

ARFLAGS	:= rcs

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(_BLANK)
	@echo "$(_HEAD)$(_GREEN)✔$(_END) ($(NAME))"
