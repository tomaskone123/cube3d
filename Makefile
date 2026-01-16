NAME		:= cube3D
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:= ./lib/MLX42
LIBFT		:= ./lib/libft

HEADERS		:= -I ./include -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a
SRCS := \
		./src/arg_checker.c \
		./src/check_duplicates.c \
		./src/colours.c \
		./src/draw.c \
		./src/error.c \
		./src/free.c \
		./src/game_loop.c \
		./src/main.c \
		./src/map_parsing.c \
		./src/map_parsing2.c \
		./src/movement.c \
		./src/parsing.c \
		./src/rays.c \
		./src/textures.c \
		./src/utils.c \
		./src/utils2.c \
		./src/utils3.c \
		./src/utils_rays.c

OBJS		:= ${SRCS:.c=.o}



all: libmlx libft $(NAME)

norm:
	@norminette src include

libft:
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) -g $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) -g $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
