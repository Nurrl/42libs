#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <lroux@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 18:52:46 by lroux             #+#    #+#              #
#    Updated: 2019/03/29 18:52:46 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
make && rm -f *.o && ar -x libprintf.a && ar -x ../liblift/liblift.a && ar rcs libftprintf.a *.o && rm -f *.o __.SYMDEF\ SORTED
