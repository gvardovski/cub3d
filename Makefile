NAME = cub3d
NAMEPRINT = ft_printf/libftprintf.a
NAMEMLX = minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -Lmlx -lXext -lX11 -lm
RM = rm -f
AR = ar rcs
SRCGET = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
SRC = map_parser/map_parser.c \
	map_parser/map_parser_add.c \
	map_parser/map_wall_path.c \
	render/render.c render/rcaster.c render/rcaster_add.c \
	render/r_helpers.c cb3d.c
OBJECTS = $(SRC:.c=.o)
OBJECTSGET = $(SRCGET:.c=.o)
%$(SRCDIR).o: %$(SRCDIR).c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Create object Cub3d"
$(NAME): $(OBJECTS) $(OBJECTSGET)
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./minilibx-linux
	@$(CC) $(SRC) $(SRCGET) $(NAMEPRINT) $(NAMEMLX) $(CFLAGS) $(MLXFLAGS) -o $(NAME)
	@echo "CC finished Cub3d"
all: $(NAME)
clean:
	$(RM) $(OBJECTS) $(OBJECTSGET)
	$(MAKE) clean -C ./ft_printf
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./ft_printf
re: fclean all
.PHONY: all clean fclean re