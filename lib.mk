# Include common stuff
include $(shell dirname $(lastword $(MAKEFILE_LIST)))/core.mk

ARFLAGS	:= rcs

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(_BLANK)
	@echo -n "$(_HEAD)$(_GREEN)✔$(_END) $(NAME)"
ifdef LNKNAME
	@$(LN) $(NAME) $(LNKNAME)
	@echo -n " $(_CYAN)⬅$(_END) $(LNKNAME)"
endif
	@echo
