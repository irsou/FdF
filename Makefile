NAME = fdf

INCLUDE_DIR = include

SRC = get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
src/allocate_map_matrix.c \
src/aux_functions.c \
src/create_image.c \
src/draw_line.c \
src/draw_line_aux.c \
src/draw_wireframe.c \
src/fill_matrix_points.c \
src/free_map.c \
src/get_initial_map_view.c \
src/handle_map_points.c \
src/hook_close.c \
src/hook_interact.c \
src/init_mlx.c \
src/main.c \
src/print_map.c \
src/process_map.c \
src/read_map.c \
src/render_map.c \

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

HEADERS = $(INCLUDE_DIR)/*.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -I$(MINILIBX_DIR) -I$(X11_INCLUDE) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L$(X11_LIB) -lX11 -lXext -lm -o $(NAME) 

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY:	all clean fclean re