# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/01/07 20:49:33 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= srcs
OBJDIR	:= objs
INCLDIR := includes


CFLAGS	:= -Wall -Wextra -Werror -I$(INCLDIR) -Ofast
LDFLAGS	:=
ARFLAGS	:= rcs

SRCS	:= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strndup.c \
		   ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		   ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
		   ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		   ft_isascii.c ft_isprint.c ft_isupper.c ft_islower.c ft_toupper.c \
		   ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		   ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		   ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
		   ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		   ft_putnbr_fd.c ft_calloc.c ft_realloc.c ft_itostr.c ft_utostr.c \
		   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		   ft_lstmap.c ft_strnjoin.c ft_strreset.c ft_strjoinfree.c \
		   ft_strnjoinfree.c ft_sqrt.c ft_cc.c ft_strupr.c ft_strlwr.c gnl.c \
		   ft_strisdigit.c ft_strisndigit.c ft_pow.c ft_intlen.c \
		   ft_uintlen.c ft_strebrk.c \
		   libprintf/wrappers.c libprintf/handlers.c libprintf/lexer.c \
		   libprintf/subst.c libprintf/map.c libprintf/utils.c \
		   libprintf/handlers/char.c libprintf/handlers/int.c \
		   libprintf/handlers/oct.c libprintf/handlers/hex.c \
		   libprintf/handlers/ptr.c libprintf/handlers/float.c \
		   libprintf/handlers/bonus.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS	:= Makefile includes/libft.h \
			includes/gnl.h includes/gnl.intern.h \
			includes/libprintf.h includes/libprintf.intern.h
NAME	:= libft.a
SO		:= libft.so

PROJECT	:= libft
include utils/utils.mk

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
