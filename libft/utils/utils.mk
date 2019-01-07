# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 17:54:55 by lroux             #+#    #+#              #
#    Updated: 2018/12/30 13:41:00 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define shell
SHELL		:= /bin/bash

# This is a minimal set of ANSI/VT100 color codes
_END		:= $(shell echo -ne "\x1b[0m")
_BOLD		:= $(shell echo -ne "\x1b[1m")
_UNDER		:= $(shell echo -ne "\x1b[4m")
_REV		:= $(shell echo -ne "\x1b[7m")

# Colors
_GREY		:= $(shell echo -ne "\x1b[30m")
_RED		:= $(shell echo -ne "\x1b[31m")
_GREEN		:= $(shell echo -ne "\x1b[32m")
_YELLOW		:= $(shell echo -ne "\x1b[33m")
_BLUE		:= $(shell echo -ne "\x1b[34m")
_PURPLE		:= $(shell echo -ne "\x1b[35m")
_CYAN		:= $(shell echo -ne "\x1b[36m")
_WHITE		:= $(shell echo -ne "\x1b[37m")

# Inverted, i.e. colored backgrounds
_IGREY		:= $(shell echo -ne "\x1b[40m")
_IRED		:= $(shell echo -ne "\x1b[41m")
_IGREEN		:= $(shell echo -ne "\x1b[42m")
_IYELLOW	:= $(shell echo -ne "\x1b[43m")
_IBLUE		:= $(shell echo -ne "\x1b[44m")
_IPURPLE	:= $(shell echo -ne "\x1b[45m")
_ICYAN		:= $(shell echo -ne "\x1b[46m")
_IWHITE		:= $(shell echo -ne "\x1b[47m")

# Custom format variables
_BLANK		:= @perl -e \
				"print \"\r\"; print \" \"x$(shell tput cols); print \"\r\""
_HEAD		:= $(shell echo -ne " $(_BOLD)$(_UNDER)▲$(PROJECT)▼$(_END) ")


