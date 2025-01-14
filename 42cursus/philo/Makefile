# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 22:52:27 by ruchoa            #+#    #+#              #
#    Updated: 2023/10/02 22:33:11 by ruchoa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKEFLAGS			=	--silent

NAME				=	philo

LIBS_A				=	$(foreach lib, $(LIBS),$(LIBS_PATH)$(lib)/$(lib).a)
LIBS_DIR			=	$(foreach lib, $(LIBS),$(LIBS_PATH)$(lib)/)
LIBS_PATH			=	../
LIBS				=	

#-I <dir>				Add directory to include search path
INCLUDE_DIR			=	$(foreach lib, $(LIBS),-I $(LIBS_PATH)$(lib)/)

#-L <dir>				Add directory to library search path
LIBRARY_DIR			=	$(foreach lib, $(LIBS),-L $(LIBS_PATH)$(lib)/)

COMPILER			=	cc
CFLAGS				=	-Wall -Wextra -Werror -pthread

AR					=	ar
AFLAGS				=	rc

REMOVE				=	rm
RFLAGS				=	-drf

SRCS				=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))
SRCS_OBJS			= 	$(SRCS:.c=.o)
SRCS_PATH			=	./
SRCS_LIST			=	main.c \
						philo.c \
						ft_atoi.c \
						ft_check_arg.c \
						ft_check_dead.c \
						ft_check_last_meal.c \
						ft_check_meals.c \
						ft_free.c \
						ft_get_time.c \
						ft_hunger.c \
						ft_init.c \
						ft_itoa.c \
						ft_msg_error.c \
						ft_msg.c \
						ft_routine_alone.c \
						ft_routine.c \
						ft_set_dead.c \
						ft_set_last_meal.c \
						ft_set_meals.c \
						ft_sleep_ms.c \
						ft_strcmp.c \

#						$(shell echo '$@ <- Nome da regra.')
#						$(shell echo '$< <- Nome da primeira dependência.')
#						$(shell echo '$^ <- Lista de dependências.')
#						$(shell echo '$? <- Lista de dependências mais recentes que a regra.')
#						$(shell echo '$* <- Nome do arquivo sem sufixo.')

.c.o:
						$(COMPILER) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

all:					$(NAME)

$(NAME):				$(SRCS_OBJS)
						$(foreach lib, $(LIBS_DIR), make all -sC $(lib);)
						$(COMPILER) $(CFLAGS) $(SRCS_OBJS) $(LIBS_A) $(LIBRARY_DIR) -o $(NAME)

debug:					$(SRCS)
						$(foreach lib, $(LIBS_DIR), make all -sC $(lib);)
						$(COMPILER) $(CFLAGS) -g $(SRCS) $(INCLUDE_DIR) $(LIBS_A) $(LIBRARY_DIR) -o $(NAME)
						gdb --args ./$(NAME) $(ARG)

clean:
						$(foreach lib, $(LIBS_DIR), make clean -sC $(lib);)
						$(REMOVE) $(RFLAGS) $(SRCS_OBJS)

fclean:					clean
						$(foreach lib, $(LIBS_DIR), make fclean -sC $(lib);)
						$(REMOVE) $(RFLAGS) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re

show:
						@printf "SYSTEM		: $(shell uname)\n"
						@printf "NAME		: $(NAME)\n"
						@printf "COMPILER	: $(COMPILER)\n"
						@printf "CFLAGS		: $(CFLAGS)\n"
						@printf "SRC		: $(SRCS)\n"

#                           +------------------ <- nop <- number_of_philosophers;
#                           | +---------------- <- ttd <- time_to_die;
#                           | |   +------------ <- tte <- time_to_eat;
#                           | |   |   +-------- <- tts <- time_to_sleep;
#                           | |   |   |   +---- <- pme <- [optional] number_of_times_each_philosopher_must_eat;
#                           | |   |   |   |
# ARG					=	5 800 200 200   # No philosopher should die.
ARG					=	5 800 200 200 7 # No philosopher should die.
# ARG					=	4 410 200 200   # No philosopher should die.
# ARG					=	4 310 200 100 7 # One philosopher should die.
# ARG					=	1 800 200 200   # The philosopher should not eat and should die
# ARG					=	5 410 200 100 7 # One philosopher should die.
# ARG					=	5 120 80 80 	# Moana tolds all will die

run:					$(NAME)
						./$(NAME) $(ARG)

valgrind:				re
						valgrind --leak-check=full --show-leak-kinds=all -s -v --track-origins=yes ./$(NAME) $(ARG)

helgrind:				re
						valgrind --tool=helgrind ./$(NAME) $(ARG)

fsanitize:				$(SRCS_OBJS)
						$(foreach lib, $(LIBS_DIR), make all -sC $(lib);)
#						$(COMPILER) $(CFLAGS) -fsanitize=thread $(SRCS_OBJS) $(LIBS_A) $(LIBRARY_DIR) -o $(NAME)
						$(COMPILER) $(CFLAGS) -fsanitize=address $(SRCS_OBJS) $(LIBS_A) $(LIBRARY_DIR) -o $(NAME)
						./$(NAME) $(ARG)

rerun:					re run
