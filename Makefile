# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 15:42:50 by hmidoun           #+#    #+#              #
#    Updated: 2019/10/16 20:21:25 by midounhocin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
		get.c \
		type_c.c \
		type_d.c \
		type_o.c \
		type_o_.c \
		type_s_l.c \
		type_s.c \
		type_u.c \
		type_u_.c \
		type_x_.c \
		type_x.c \
		ft_atoi.c \
		ft_putstr_buff.c \
		ft_putchar_buff.c \
		ft_putnbr_unsigned_buf.c \
		type_f.c \
		type_f_.c \
		type_d_.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_ls_push_back.c \
	ft_ls_size.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_rot.c \
	ft_split.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	ft_sqrt_max.c \
	ft_abs.c \
	ft_splitdel.c \
	ft_putnbr_unsigned.c \
	ft_max.c \
	ft_min.c \
	ft_itoa_base.c

HEADER = ./includes/ft_printf.h \
		 		./includes/libft.h

INCLUDE_PATH = -I ./includes

OBJ = $(patsubst %.c, obj/%.o, $(SRC))
CC = gcc
FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

obj:
	mkdir -p obj

obj/%.o: src/%.c $(HEADER) | obj
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDE_PATH)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean
