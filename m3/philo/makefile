NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
SRCS = main.c \
	   init_philo.c init_table.c \
	   monitor.c \
	   philo_parse.c philo_print.c philo_task_fork.c philo_task_single.c philo_task.c philo_task_utils.c \
	   state.c thread.c \
	   time.c wait.c \
	   cleanup.c

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