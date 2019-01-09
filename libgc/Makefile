# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/01/08 17:18:59 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= srcs
OBJDIR	:= objs
INCLDIR := includes


CFLAGS	:= -Wall -Wextra -Werror -I$(INCLDIR)
LDFLAGS	:=
ARFLAGS	:= rcs

SRCS	:= alloc.c cleaner.c list.c wrappers.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS	:= Makefile includes/libgc.h \
		   includes/libgc.both.h includes/libgc.intern.h
NAME	:= libgc.a
SO		:= libgc.so

PROJECT	:= libgc
include ../libft/utils/utils.mk

all: $(NAME)

so: $(SO)

$(NAME): $(OBJS)
	$(_BLANK)
	@echo "$(_HEAD)$(_GREEN)✔$(_END) ($(NAME))"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(SO): $(OBJS)
	$(_BLANK)
	@echo "$(_HEAD)$(_GREEN)✔$(_END) ($(SO))"
	@$(LD) $(LDFLAGS) -shared -o $(SO) $(OBJS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPS)
	$(_BLANK)
	@echo -n "$(_HEAD)$< $(_GREEN)➤$(_END) $@"
	@[ ! -d $(shell dirname $@) ] && mkdir -p $(shell dirname $@) || true
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(_HEAD)$(_RED)⨯$(_END) objs"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(_HEAD)$(_RED)⨯$(_END) exec"
	@$(RM) $(NAME)
	@$(RM) $(SO)

re: fclean all

.PHONY: all so clean fclean re
