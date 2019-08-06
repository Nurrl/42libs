# Include common stuff
include $(shell dirname $(lastword $(MAKEFILE_LIST)))/core.mk

# Getting dependencies for subsequent libraries
$(foreach libfile, $(LIBSFILES), \
	$(eval LIBSDEPS.$(notdir $(libfile)) := \
		$(addprefix $(dir $(libfile)), \
			$(shell $(MAKE) -sC $(dir $(libfile)) show-deps))) \
)

# Creating dependency targets
$(foreach libfile, $(LIBSFILES), \
$(eval $(libfile): $(LIBSDEPS.$(notdir $(libfile)))) \
)

export DEBUG
$(LIBSFILES):
	@$(MAKE) -C $(dir $@)

$(NAME): $(LIBSFILES) $(OBJS)
	@$(LD) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	$(_BLANK)
	@echo -n "$(_HEAD)$(_GREEN)✔$(_END) $(NAME)"
ifndef LNKNAME
	@echo
endif
