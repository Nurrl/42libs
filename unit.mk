# Check if variables are undefined
ifndef UNITDIR
    $(error Variable UNITDIR is not set.)
endif
ifndef UNITS
    $(error Variable UNITS is not set.)
endif

include $(LIBDIR)/defines.mk

UNITS	:= $(addsuffix .unit, $(UNITS))

unit: $(UNITS)

%.unit: $(UNITDIR)/% $(NAME) $(LNKNAME)
	@source "$<"; \
		echo -ne "▽ Unit test $(_UNDER)$$name$(_END)... "; \
		output="$$($(NAME) "$$params" 2>&1)"; \
		code="$$?"; \
		[ "$$code" -eq "$$return" ] \
			&& ( \
				[[ "$$output" =~ $$regex ]] \
					&& echo -e "$(_SUCCS)" \
					|| ( \
						echo -e "$(_FAILR)"; \
						echo -e "> $(_UNDER)Trace$(_END):\n $(_RED)$$output$(_END)\n" \
							"isn't matching regex\n" \
							"$(_RED)$$regex$(_END)"; \
					) \
				) \
			|| ( \
				echo -e "$(_FAILR)"; \
				echo -e "> $(_UNDER)Trace$(_END): return-code mismatch\n" \
					"expected $(_RED)$$return$(_END), but got $(_RED)$$code$(_END)."; \
			)

.PHONY: unit %.unit
