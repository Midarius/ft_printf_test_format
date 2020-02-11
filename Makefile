# FT_PRINT FOLDER
# MAKE SURE YOUR FT_PRINTF IS COMPILED
FT_PRINTF = ../ft_printf

# -DFANCY
# disable colored output
# -DEDGE
# disable test that cause warnings
DEF =

CC = gcc

CFLAGS = -Wall -Wextras

NAME = ft_printf_test_format

SRC = ft_printf_test_format.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(DEF) -L$(FT_PRINTF) -lftprintf
	./$(NAME)

.PHONY = fclean

fclean:
	rm $(NAME)
