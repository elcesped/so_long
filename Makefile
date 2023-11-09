# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 11:58:05 by elcesped          #+#    #+#              #
#    Updated: 2023/09/15 14:53:16 by elcesped         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
RM = rm -fr
SRC = so_long.c maps.c check_line.c move.c load_img.c clean.c sprite.c enemy.c utils.c\
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
libft/ft_bzero.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_putchar_fd.c\
libft/ft_substr.c libft/ft_strnstr.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_itoa.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) mlx_linux/libmlx_linux.a
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

mlx_linux/libmlx_linux.a:
	cd mlx_linux; ./configure
	
%.o : %.c
#	$(CC) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all

.PHONY: all clean fclean re