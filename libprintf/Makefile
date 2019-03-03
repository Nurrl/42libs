# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/03 21:59:36 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= libprintf
NAME	:= build/$(PROJECT).a
LNKNAME	:= $(PROJECT).a

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= \
			wrappers/printf.c \
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

DEBUG	:= 1

# Include core
include $(LIBDIR)/lib.mk

