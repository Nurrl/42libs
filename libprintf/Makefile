# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/04/10 21:39:16 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= "\<\> libprintf :"
EX		:= libprintf
NAME	:= build/$(EX).a
LNKNAME	:= $(EX).a

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= \
			wrappers/printf.c \
			wrappers/dprintf.c \
			wrappers/sdprintf.c \
			wrappers/snprintf.c \
			wrappers/asprintf.c \
		   \
			lexer.c map.c \
			flag.c special.c \
			entry.c \
		   \
			handlers/char.c handlers/int.c handlers/ptr.c \
			handlers/oct.c handlers/hex.c handlers/bonus.c \
			handlers/float.c

LIBS	:= liblift
LIBDIR	:= ..

#DEBUG	:= 1

# Include core
include $(LIBDIR)/lib.mk

