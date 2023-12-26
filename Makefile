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

BONUS_FILES		=	main.c \
					input_parsing/input_parsing.c \
					input_parsing/input_parsing_extras.c \
					cstack/cstack.c \
					cstack/cstack_manip.c \
					cstack/cstack_linking_utils.c \
					cstack/cstack_manip_rotates.c

SRC_DIR			= 	src
BONUS_DIR		=	src_bonus
OBJ_DIR			= 	obj
BONUS_OBJ_DIR	=	obj_bonus
SRC				= 	$(addprefix $(SRC_DIR)/, $(FILES))
BONUS_SRC		= 	$(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
BONUS_OBJ		= 	$(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o))

CC				=	gcc

NAME			= 	push_swap
BONUS_NAME		=	checker
HEADER_DIR		= 	include
BONUS_HEAD_DIR	=	include_bonus
LIBFT_DIR 		= 	libft
LIBFT			= 	$(LIBFT_DIR)/libft.a

INCLUDES		= 	-I$(HEADER_DIR) -I$(LIBFT_DIR)
#CC_DEBUG 		= 	-fsanitize=address -fno-omit-frame-pointer
#L_DEBUG		=	-lasan
#ERROR_FLAGS 	= 	-Wall -Werror -Wextra
L_FLAGS			=	-lft

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) $(L_FLAGS) -o $@

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ_DIR) $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -L$(LIBFT_DIR) $(L_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $@ -g
	@echo "$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $(notdir $@) -g"

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $@ -g
	@echo "$(CC) $(CC_DEBUG) $(include_bonus) $(ERROR_FLAGS) -c $< -o $(notdir $@) -g"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/cstack $(OBJ_DIR)/input_parsing $(OBJ_DIR)/sort  

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)/cstack $(BONUS_OBJ_DIR)/input_parsing

$(LIBFT): libft/Makefile
	make -C libft

libft/Makefile:
	@git submodule init
	@git submodule update

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

clean_bonus:
	rm -rf $(BONUS_OBJ_DIR)
	rm -r $(BONUS_NAME)

fclean: clean clean_bonus
	make -C $(LIBFT_DIR) fclean

re: clean all

valgrind: all
	valgrind --leak-check=full ./$(NAME) 3456 34 2 1                                           

.PHONY: all clean fclean re bonus valgrind clean_bonus
