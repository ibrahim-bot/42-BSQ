# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/08/21 19:24:42 by lumeyer      #+#   ##    ##    #+#        #
#    Updated: 2019/08/21 21:23:36 by ichougra    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	=	bsq

CC		=	cc

RM		=	rm -f

SRC		=	./srcs/main.c\
			./srcs/numbers.c\
			./srcs/base.c\
			./srcs/ft_get.c\
			./srcs/ft_print.c\
			./srcs/ft_alloc.c\
			./srcs/error.c

OBJ		=	$(SRC:.c=.o)

CFLAGS 	=	-g -O3 -Werror -Wall -Wextra -I ./includes/ 

RM		=	rm -f

all : $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c includes/header.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
