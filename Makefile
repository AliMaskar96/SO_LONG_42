# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 14:23:32 by aait-mas          #+#    #+#              #
#    Updated: 2022/04/20 01:46:04 by aait-mas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	so_long

SRCS =	so_long.c check_map.c check_elements.c \
		draw_map1.c draw_map2.c image_initialization.c manage_moves1.c manage_moves2.c \
		so_long_utils1.c so_long_utils2.c \
		get_next_line.c get_next_line_utils.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

%.o:	%.c
		$(CC) -Wall -Wextra -Werror -g -Imlx -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all