# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:24:43 by lmery             #+#    #+#              #
#    Updated: 2021/12/14 15:30:48 by lmery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m


NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -rf

FILES =	ft_printf \
	ft_putchar_n \
	ft_putstr_n \
	ft_type \
	ft_flag \
	ft_flag_int \
	ft_apply_flag \
	ft_putchar \
	ft_putnbrbase_n \
	ft_putx \
	ft_putui \
	ft_strlen \
	ft_strlen_arg \
	ft_strdup \
	ft_ub \


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^
	@printf "\033[2K\r$(_GREEN) Yep, all files compiled in here. $(_END)✅\n"

bonus: $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)
	@printf "$(_YELLOW) Bonus Done ! $(_END)\n"

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_B)
	@printf "$(_PURPLE) All the .o files has been deleted. $(_END)\n"

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re

