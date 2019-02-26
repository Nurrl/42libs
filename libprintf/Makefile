# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/02/25 18:59:34 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= libprintf
NAME	:= build/$(PROJECT).a
LNKNAME	:= $(PROJECT).a

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= wrappers.c handlers.c lexer.c map.c utils.c special.c \
		   handlers/char.c handlers/int.c handlers/ptr.c \
		   handlers/oct.c handlers/hex.c handlers/bonus.c \
		   handlers/float.c

LIBS	:= liblift
LIBDIR	:= ..

# Include core
include $(LIBDIR)/lib.mk

