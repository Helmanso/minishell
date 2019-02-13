# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helmanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/13 19:57:42 by helmanso          #+#    #+#              #
#    Updated: 2019/02/13 15:18:37 by helmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/ft_callfunctions.c src/ft_cd.c src/ft_echo.c src/ft_envmanager.c src/ft_flags.c src/ft_fork.c src/ft_setenv.c src/ft_signal.c src/ft_strstplittok.c src/ft_tablemanager.c src/ft_unsetenv.c src/get_next_line.c

FLAGS = gcc -Wall -Werror -Wextra -o

all : $(NAME)

$(NAME):
	@make -C libft/
	@$(FLAGS) $(NAME) $(SRC) libft/libft.a

clean :
	@rm -f libft/*.o

fclean:
	@make fclean -C libft/
	@rm -f $(NAME)

re : fclean all
