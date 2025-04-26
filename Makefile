NAME = fdf

INCLUDE_DIR = include

SRC = src/main.c \
src/parse_file.c \
src/print_map.c \
src/free_map.c \
src/process_map.c \
src/render_map.c \
src/create_image.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
src/hook_aux.c \
src/aux_functions.c \

OBJ = $(SRC:.c=.o)

CC = cc
# FLAGS = -Wall -Werror -Wextra
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = mlx
LIBMLX = $(MINILIBX_DIR)/libmlx.a
X11_INCLUDE = /usr/include
X11_LIB = /usr/lib

%.o: src/%.c
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -I$(MINILIBX_DIR) -I$(X11_INCLUDE) -c $< -o $@

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L$(X11_LIB) -lX11 -lXext -lm -o $(NAME) 

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY:	all clean fclean re