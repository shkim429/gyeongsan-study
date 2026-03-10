NAME = philo
CC = cc
CFLAGS = $(INC) -g
RM = rm -rf
SRCS = main.c \
	   valid_input.c valid_input_utils.c \
	   general_func_utils.c \
	   free_res.c
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS_PATH = -L.

INC = -I.
	
all : $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBS_PATH) -o $(NAME)

clean :
	$(RM) $(OBJ_DIR)


fclean : clean
	$(RM) $(NAME)

re : fclean all
	
.PHONY : all clean fclean re