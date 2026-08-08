NAME = getnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = get_next_line_utils.c get_next_line.c

OBJS = ${SRCS:.c=.o}
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))


all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar -rcs $(NAME) $(OBJS_FILES)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all
	
.PHONY : all clean fclean re