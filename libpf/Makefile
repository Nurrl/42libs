# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/02/21 14:53:27 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= libpf
NAME	:= build/$(PROJECT).a
LNKNAME	:= $(PROJECT).a

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= wrappers.c handlers.c lexer.c map.c utils.c subst.c \
		   handlers/char.c handlers/int.c handlers/ptr.c \
		   handlers/oct.c handlers/hex.c handlers/bonus.c \
		   handlers/float.c

LIBS	:= liblift
LIBDIR	:= ..

# Include core
include ../lib.mk

