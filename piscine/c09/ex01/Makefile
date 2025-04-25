CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes

SRC = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJ = $(SRC:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

LIBRARY = libft.a

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	ar rcs $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:  
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBRARY)

re: fclean all

.PHONY: all clean fclean re

