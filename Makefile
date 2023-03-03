CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCDIR = ./src
OBJDIR = ./objects
BONUS_DIR = ./bonus

SRCS = $(shell find $(SRCDIR) -name "*.c")
OBJS_MAN = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

BONUS_DIR = ./bonus
SRCS_BONUS = $(shell find $(BONUS_DIR) -name "*.c")
OBJS_BONUS = $(patsubst $(BONUS_DIR)/%.c,$(OBJDIR)/bonus/%.o,$(SRCS_BONUS))

INCLUDE = -I ./include/

RM = rm -rf

FILE_NAME = push_swap
FILE_NAME_BONUS = checker

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m


.PHONY : all bonus clean fclean re

all: $(FILE_NAME)  Makefile

bonus: $(FILE_NAME_BONUS) Makefile

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/bonus/%.o: $(BONUS_DIR)/%.c | $(OBJDIR)/bonus
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/bonus: $(OBJDIR)
	mkdir -p $(OBJDIR)/bonus

$(OBJDIR): Makefile
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/operations
	mkdir -p $(OBJDIR)/sorting
	mkdir -p $(OBJDIR)/utils

$(FILE_NAME): $(OBJS_MAN)
	@echo "$(YELLOW)Linking $(FILE_NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) $^ -o $(FILE_NAME)
	@echo "$(GREEN)Done!$(RESET)"

$(FILE_NAME_BONUS): $(OBJS_BONUS) 
	@echo "$(YELLOW)Compiling bonus...$(RESET)"
	@$(CC) $(INCLUDE) $^ -o $(FILE_NAME_BONUS)
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@$(RM) $(OBJS_MAN) $(OBJS_BONUS)
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@echo "$(RED)Removing out file...$(RESET)"
	@$(RM) $(FILE_NAME) $(FILE_NAME_BONUS)
	@echo "$(GREEN)Done!$(RESET)"

re: fclean all bonus



#<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>
#<<<<<<<<<<<<<<<<<< TESTS >>>>>>>>>>>>>>>>>>>
#<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>

test1:
	$(eval ARG = $(shell jot -r 100 -2147483648 2147483647))
	@./$(FILE_NAME)  $(ARG) | wc -l 
	@./$(FILE_NAME)  $(ARG) | ./checker_Mac $(ARG) 

test2:
	$(eval ARG = $(shell jot -r 500 -2147483648 2147483647))
	@./$(FILE_NAME)  $(ARG) | wc -l 
	@./$(FILE_NAME)  $(ARG) | ./checker_Mac $(ARG) 

alltest: test1 test2


my_test1:
	$(eval ARG = $(shell jot -r 100 -2147483648 2147483647))
	@./$(FILE_NAME)  $(ARG) | wc -l 
	@./$(FILE_NAME)  $(ARG) | ./checker_Mac $(ARG) 

my_test2:
	$(eval ARG = $(shell jot -r 500 -2147483648 2147483647))
	@./$(FILE_NAME)  $(ARG) | wc -l 
	@./$(FILE_NAME)  $(ARG) | ./checker_Mac $(ARG) 