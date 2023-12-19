FILES			= 	main.c \
					cstack/cstack.c \
					cstack/cstack_manip.c \
					input_parsing.c \
					sort.c
							
SRC_DIR			= 	src
OBJ_DIR			= 	obj
SRC				= 	$(addprefix src/, $(FILES))
OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CC				=	gcc

NAME			= 	push_swap
HEADER_DIR		= 	include
LIBFT_DIR 		= 	libft
LIBFT			= 	$(LIBFT_DIR)/libft.a

INCLUDES		= 	-I$(HEADER_DIR) -I$(LIBFT_DIR)
#CC_DEBUG 		= 	-fsanitize=address -fno-omit-frame-pointer
#L_DEBUG		=	-lasan
#ERROR_FLAGS 	= 	-Wall -Werror -Wextra
L_FLAGS			=	-lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ))) -L$(LIBFT_DIR) $(L_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $(OBJ_DIR)/$(notdir $@) -g
	@printf '%-30s -> %30s\n' "$<" "$(notdir $@)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

fclean: clean
	make -C $(LIBFT_DIR) fclean

re: clean all

valgrind: all
	valgrind --leak-check=full ./$(NAME) 2 3 1

.PHONY: all clean fclean re
