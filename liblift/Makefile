# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/02/21 14:51:28 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= liblift
NAME	:= build/$(PROJECT).a
LNKNAME	:= $(PROJECT).a

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= \
			char/ft_isalnum.c \
			char/ft_isalpha.c \
			char/ft_isascii.c \
			char/ft_isdigit.c \
			char/ft_islower.c \
			char/ft_isprint.c \
			char/ft_isspace.c \
			char/ft_isupper.c \
			char/ft_tolower.c \
			char/ft_toupper.c \
		   \
			io/gnl.c \
		   \
			list/ll_add.c \
			list/ll_del.c \
			list/ll_dup.c \
			list/ll_len.c \
			list/ll_get.c \
			list/ll_pop.c \
		   \
			math/ft_atoi.c \
			math/ft_intlen.c \
			math/ft_itostr.c \
			math/ft_pow.c \
			math/ft_sqrt.c \
			math/ft_uintlen.c \
			math/ft_utostr.c \
			math/ft_strtoll.c \
		   \
			memory/ft_bzero.c \
			memory/ft_calloc.c \
			memory/ft_memccpy.c \
			memory/ft_memchr.c \
			memory/ft_memcmp.c \
			memory/ft_memcpy.c \
			memory/ft_memdel.c \
			memory/ft_memmove.c \
			memory/ft_memset.c \
			memory/ft_mk2array.c \
			memory/ft_realloc.c \
		   \
			string/ft_strcc.c \
			string/ft_strcw.c \
			string/ft_strcat.c \
			string/ft_strchr.c \
			string/ft_strclr.c \
			string/ft_strcmp.c \
			string/ft_strcpy.c \
			string/ft_strdel.c \
			string/ft_strdup.c \
			string/ft_strebrk.c \
			string/ft_strequ.c \
			string/ft_strisdigit.c \
			string/ft_strisndigit.c \
			string/ft_strjoin.c \
			string/ft_strjoinfree.c \
			string/ft_strlcat.c \
			string/ft_strlen.c \
			string/ft_strlwr.c \
			string/ft_strncat.c \
			string/ft_strncmp.c \
			string/ft_strncpy.c \
			string/ft_strndup.c \
			string/ft_strnequ.c \
			string/ft_strnew.c \
			string/ft_strnjoin.c \
			string/ft_strnjoinfree.c \
			string/ft_strnstr.c \
			string/ft_strrchr.c \
			string/ft_strreset.c \
			string/ft_strsplit.c \
			string/ft_strstr.c \
			string/ft_strsub.c \
			string/ft_strtrim.c \
			string/ft_strupr.c \

LIBS	:=
LIBDIR	:= ..

# Include core
include ../lib.mk
