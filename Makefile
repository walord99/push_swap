FILES			= 	main.c \
					cstack/cstack.c \
					cstack/cstack_manip.c \
					cstack/cstack_linking_utils.c \
					cstack/cstack_manip_rotates.c \
					input_parsing/input_parsing.c \
					input_parsing/input_parsing_extras.c \
					sort/sort.c \
					sort/spin.c \
					sort/get_move_info.c \
					sort/find_least_move.c 
							
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
ERROR_FLAGS 	= 	-Wall -Werror -Wextra
L_FLAGS			=	-lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) -L$(LIBFT_DIR) $(L_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $@ -g
	@echo "$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $(notdir $<) -o $(notdir $@) -g"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/cstack $(OBJ_DIR)/input_parsing $(OBJ_DIR)/sort  

$(LIBFT): libft/Makefile
	make -C libft

libft/Makefile:
	@git submodule init
	@git submodule update

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

fclean: clean
	make -C $(LIBFT_DIR) fclean

re: clean all

valgrind: all
	valgrind --leak-check=full ./$(NAME) 3456 34 2 1                                           

.PHONY: all clean fclean re
