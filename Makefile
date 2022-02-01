# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# VARIABLES #
NAME = Minitalk
SVR_NAME	= server
CLNT_NAME	= client
LIBFT_NAME = libft.a
PRINTF_NAME = printf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g3
CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT_PATH)

# PATHs #
LIBFT_PATH  = srcs/libft
PRINTF_PATH  = srcs/printf
INC_PATH    = includes
SRC_PATH    = srcs
OBJ_PATH    = objects


# SOURCES #
SRC =   client.c\
        server.c

# RULES #
all: $(NAME)

OBJS_NAME = $(SRC:%.c=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
            
$(NAME): $(OBJS) | $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(SRC_PATH)/server.c -o $(SVR_NAME) $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME)) $(addprefix $(PRINTF_PATH)/, $(PRINTF_NAME))
	$(CC) $(CFLAGS) $(SRC_PATH)/client.c -o $(CLNT_NAME) $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME)) $(addprefix $(PRINTF_PATH)/, $(PRINTF_NAME))

$(LIBFT_NAME):
	$(MAKE) -sC $(LIBFT_PATH)
	$(MAKE) -sC $(PRINTF_PATH)

##RULES
$(MAKE): make

norminette:
	norminette $(SRCS)
	norminette $(LIBFT_PATH)
	norminette $(PRINTF_PATH)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(SVR_NAME)
	rm -rf $(CLNT_NAME)
	rm -rf $(OBJ_PATH)
	make fclean -sC $(LIBFT_PATH)
	make fclean -sC $(PRINTF_PATH)

re: fclean all

PHONY.: all clean fclean re norminette