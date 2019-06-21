# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/06/18 14:53:57 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= "▶ liblift :"
EX		:= liblift
NAME	:= build/$(EX).a
LNKNAME	:= $(EX).a

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= \
			char/ft_inset.c \
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
			argp/ft_argp.c \
		   \
			io/gnl.c \
		   \
			list/ll_add.c \
			list/ll_del.c \
			list/ll_dup.c \
			list/ll_len.c \
			list/ll_get.c \
			list/ll_pop.c \
			list/ll_shift.c \
			list/ll_swap.c \
		   \
			math/ft_min.c \
			math/ft_atoi.c \
			math/ft_intlen.c \
			math/ft_itostr.c \
			math/ft_itostrb.c \
			math/ft_pow.c \
			math/ft_sqrt.c \
			math/ft_uintlen.c \
			math/ft_utostr.c \
			math/ft_utostrb.c \
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
			memory/ft_bswp16.c \
			memory/ft_bswp32.c \
		   \
			string/ft_strcc.c \
			string/ft_strncc.c \
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
			string/ft_stris.c \
			string/ft_strisn.c \
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
			string/ft_strrep.c \
			string/ft_strnrep.c \
			string/ft_strspn.c \
			string/ft_strnspn.c \
			string/ft_strcspn.c \
			string/ft_strncspn.c \
			string/ft_strtrim.c \
			string/ft_strtok.c \
			string/ft_strupr.c \

LIBS	:=
LIBDIR	:= ..

#DEBUG	:= 1

# Include core
include ../lib.mk
