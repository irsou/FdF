NAME = fdf

SRC = main.c \
parse_file.c \
print_map.c \
free_map.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
#render_map.c \

OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = mlx
LIBMLX = $(MINILIBX_DIR)/libmlx.a

%.o: %.c $(MINILIBX_DIR)/mlx.h
	$(CC) $(FLAGS) -I$(MINILIBX_DIR) -c $< -o $@

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -o $(NAME) 

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