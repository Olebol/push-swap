NAME := push_swap
NICKNAME := PUSH SWAP

# Directories
HDR_DIR := include
LIB_DIR := lib
SRC_DIR := src
OBJ_DIR := obj

# Compiler flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g

# Includes
HDR_FILES :=	push_swap.h

# Libft
LIBFT_DIR		:= $(LIB_DIR)/Libft
LIB				:= $(LIBFT_DIR)/libft.a

# Files
SRC_FILES :=	main.c				\
				input.c				\
				cleanup.c			\
				delete_this.c		\
				lst/swap_and_push.c	\
				lst/rotate.c		\

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.c=.o}}
HDR := $(addprefix $(HDR_DIR)/, $(HDR_FILES))

# Colours
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
RED		:= \033[31;1m
BOLD	:= \033[1m
RESET	:= \033[0m

# Rules
all: ${NAME}

$(NAME): $(OBJ) $(LIB)
	@printf "%b%s%b" "$(YELLOW)$(BOLD)" "Compiling $(NICKNAME)..." "$(RESET)"
	@gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 
	@printf "\t\t%b%s%b\n" "$(GREEN)$(BOLD)" "[OK]" "$(RESET)"

$(LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: src/%.c $(HDR)
	@mkdir -p obj
	@mkdir -p "obj/lst"
	@gcc $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

norminette:
	@norminette $(SRC)

bonus:
	@make -C ./bonus
	@mv bonus/checker ./

clean:
	@echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C ./bonus

fclean:
	@echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@rm -rf ${NAME}
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C ./bonus

re: fclean ${NAME}

.PHONY: all norminette bonus clean fclean re