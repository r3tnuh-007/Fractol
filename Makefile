# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aluis <aluis@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 19:23:03 by aluis             #+#    #+#              #
#    Updated: 2025/09/15 03:07:38 by aluis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
HEADER = fractol.h
CFLAGS = -lXext -lX11 -lm -lz -g
MINILIBX = libmlx_Linux.a
RM = rm -f

SRC =	events.c\
		init.c\
		main.c\
		m_map.c\
		m_square_complex.c\
		m_sum_complex.c\
		r_fractal_render.c\
		r_handle_pixel.c\
		r_my_pixel_put.c\
		s_ft_strncmp.c\
		s_putstr_fd.c\

NAME = fractol

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) $^ $(MINILIBX) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

bonus: all

.PHONY: all fclean re bonus
