SRCS = ft_write_char.c ft_write_string.c ft_write_pointer.c \
ft_write_decimal.c ft_write_integer.c ft_write_unsigned_integer.c  \
ft_write_hexadecimal_min.c ft_write_hexadecimal_max.c ft_printf.c \
ft_putnbr.c

OBJS = ${SRCS:.c=.o}

NAME = printf.a 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}
fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re 
