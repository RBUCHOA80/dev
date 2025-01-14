# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 22:35:12 by ruchoa            #+#    #+#              #
#    Updated: 2023/06/10 11:18:44 by ruchoa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKEFLAGS	=	--silent

NAME				=	fractol

LIBFT_PATH			=	../../libft/
LIBFT_NAME			=	libft.a
LIBFT				=	$(LIBFT_PATH)$(LIBFT_NAME)

INC					=	-I ./includes/ \
						-I $(LIBFT_PATH) \
						-I $(MLX_PATH) \

COMPILER			=	cc
CFLAGS				=	-Wall -Wextra -Werror

MLX_NAME			=	libmlx.a
MLX					=	$(MLX_PATH)$(MLX_NAME)

SRC_PATH			=	./src/
SRC					=	fractol.c \
						color.c \
						events.c \
						ft_ishexdigit.c \
						ft_isspace.c \
						help_msg.c \
						initialization.c \
						parse_args.c \
						render.c \
						utils.c \
						fractal_sets/mandelbrot.c \
						fractal_sets/julia.c \
						fractal_sets/burning_ship.c \
						fractal_sets/tricorn.c \
						fractal_sets/mandelbox.c \
						color_schemes/color_interpolated.c \
						color_schemes/color_special.c \
						color_schemes/color_striped.c \

SRCS				=	$(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH			=	./obj/
OBJ					=	$(SRC:.c=.o)
OBJS				=	$(addprefix $(OBJ_PATH), $(OBJ))

ifeq ($(shell uname), Darwin)	#MacOS
	SYSTEM			=	@printf "\e[1;33mMacOS detected.\n\e[m"
	MLX_PATH		=	../../libmlx/_macos/
	MLX_LIB			=	-lmlx -framework AppKit -framework OpenGL
	INTALL			=	Brew install Xquartz ; reboot
else							#Linux
	SYSTEM			=	@printf "\e[1;33mLinux detected.\n\e[m"
	MLX_PATH		=	../../libmlx/_linux/
	MLX_LIB			=	-lXext -lX11 -lm
	INSTALL			=	sudo apt install -y make gcc xorg libxext-dev libbsd-dev zlib1g-dev
endif

#						$(shell echo '$@ <- Nome da regra.')
#						$(shell echo '$< <- Nome da primeira dependência.')
#						$(shell echo '$^ <- Lista de dependências.')
#						$(shell echo '$? <- Lista de dependências mais recentes que a regra.')
#						$(shell echo '$* <- Nome do arquivo sem sufixo.')

$(OBJ_PATH)%.o:			$(SRC_PATH)%.c
						$(COMPILER) $(CFLAGS) -c $< -o $@ $(INC)

all:					$(MLX) $(LIBFT) $(NAME)

bonus:					all

$(OBJS):				$(OBJ_PATH)

$(NAME):				$(OBJS)
						make -sC $(MLX_PATH)
						make -sC $(LIBFT_PATH)
						$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(MLX_LIB)
						$(SYSTEM)

$(OBJ_PATH):
						mkdir -p $(OBJ_PATH)
						mkdir -p $(OBJ_PATH)fractal_sets/
						mkdir -p $(OBJ_PATH)color_schemes/

$(MLX):
						make -sC $(MLX_PATH)

$(LIBFT):
						make -sC $(LIBFT_PATH)

clean:
						rm -rf $(OBJ_PATH)
						make clean -sC $(MLX_PATH)
						make clean -sC $(LIBFT_PATH)

fclean:					clean
						rm -f $(NAME)
						rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re:						fclean all

.PHONY:					all re clean fclean

run:					$(NAME)
						./$(NAME) M

vrun:					$(NAME)
						valgrind --leak-check=full -s -v ./$(NAME) M

rerun:					re run
