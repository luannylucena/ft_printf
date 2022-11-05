NAME = libftprintf.a

SRC = ft_printf.c  #coloco aqui todos os meus arquivos '.c' que criei

OBJS = $(SRC:.C=.0) #em 'src' pego tud que é .c e transformo em .os

all: $(NAME)

$(NAME): $(OBJS)
	ar -rsc $(NAME) $(OBJS)

$(OBJS):
	gcc -Wall -Werror -Wextra -c $(@:.o=.c) .o $@ 
#o '$(@:.o=.c) pega tudo que é .o e trasforma em .c; E $@ indica qual o alvo da regra, que no caso é -o
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
