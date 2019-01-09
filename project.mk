# Include common stuff
MODULE	:= project
include $(dir $(lastword $(MAKEFILE_LIST)))core.mk

$(NAME): $(OBJS)
	@$(LD) $(LDFLAGS) $(NAME) $(OBJS)
	$(_BLANK)
	@echo "$(_HEAD)$(_GREEN)✔$(_END) ($(NAME))"
