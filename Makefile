NAME = libftprintf.a

SRC = ft_printf.c  ft_for_numbers.c ft_for_letters.c

OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	ar -rsc $(NAME) $(OBJS)

$(OBJS):
	gcc -Wall -Werror -Wextra -c $(@:.o=.c) 

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
