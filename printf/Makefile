NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rcs $(NAME) *.o
	@echo "✅"

clean:
	@rm -f *.o *a.out
fclean: clean
	@rm -f $(NAME)
	@echo "🗑️"

re: fclean all

.PHONY: all clean fclean re