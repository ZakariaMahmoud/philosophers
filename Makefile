# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:25:54 by zmahmoud          #+#    #+#              #
#    Updated: 2022/07/03 12:55:49 by zmahmoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =functions/ft_isdigit.c\
	functions/ft_atoi.c\
	functions/ft_checker.c\
	functions/ft_init.c\
	functions/philo_helper.c\
	functions/converter.c\
	philo.c\

# FLAGS = -Wall -Werror -Wextra
FLAGS= -fsanitize=thread

NAME = philo
OBJS = $(subst .c,.o,$(SRCS))

$(NAME): $(OBJS)
	gcc  $(SRCS) $(FLAGS) -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all