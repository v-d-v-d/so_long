# Nom de la bibliothèque
NAME = so_long

# Compilateur et drapeaux
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ilibft -Ignl  

# Fichiers sources et objets
SRC =	gnl/get_next_line.c \
	\
	so_long.c \
	\
	parsing/parsing.c \
	parsing/get_map.c \
	parsing/map_is_closed.c \
	parsing/char_checker.c \
	parsing/take_all_C.c \
	\
	rendering/rendering.c \
	rendering/display_map.c \
	rendering/moving.c\
	

OBJ = $(SRC:.c=.o)

# Règle all
all: $(NAME)

# Règles pour créer l'exécutable
$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

# Règle clean
clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

# Règle fclean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

# Règle re
re: fclean all

.PHONY: all clean fclean re
