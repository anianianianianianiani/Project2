NAME = push_swap
BONUS = checker
CC = cc
OBJS_DIR = objs
BONUS_OBJS_DIR = objs
SRCS_DIR = src
FLAGS =  -Wall -Werror -Wextra -g -Iincludes
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
RM = rm -rf
MKDIR = mkdir -p

.DEFAULT_GOAL = all
all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)


$(NAME): $(OBJS) | $(OBJS_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "$m"
	@git push

.PHONY: all clean fclean re push
