NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRCDIR = src
SRC = $(SRCDIR)/ft_printf.c \
	$(SRCDIR)/ft_putchar.c \
	$(SRCDIR)/ft_putstr.c \
	$(SRCDIR)/ft_putptr.c \
	$(SRCDIR)/ft_putundec.c \
	$(SRCDIR)/ft_putdec.c \
	$(SRCDIR)/ft_putnumbase.c \
	$(SRCDIR)/ft_puthex.c \
	$(SRCDIR)/ft_puthexup.c \
	$(SRCDIR)/ft_puthexp.c 
OBJECTS = $(SRC:.c=.o)
%$(SRCDIR).o: %$(SRCDIR).c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Create object printf"
$(NAME): $(OBJECTS) 
	@$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJECTS)
	@echo "CC complite printf"
all: $(NAME)
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) 
re: fclean all
.PHONY: all clean fclean re
