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

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re