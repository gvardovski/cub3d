NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs
SRCGET = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
SRC = map_parser/map_parser.c 
OBJECTS = $(SRC:.c=.o)
OBJECTSGET = $(SRCGET:.c=.o)
%$(SRCDIR).o: %$(SRCDIR).c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJECTS) $(OBJECTSGET)
	$(CC) $(SRC) $(SRCGET) $(CFLAGS) -o $(NAME)
all: $(NAME)
clean:
	$(RM) $(OBJECTS) $(OBJECTSGET)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
