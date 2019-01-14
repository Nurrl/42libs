# Include common stuff
include $(shell dirname $(lastword $(MAKEFILE_LIST)))/core.mk

$(NAME): $(LIBFILES) $(OBJS)
	@$(LD) $(OBJS) $(LDFLAGS) -o $(NAME)
	$(_BLANK)
	@echo "$(_HEAD)$(_GREEN)✔$(_END) ($(NAME))"
