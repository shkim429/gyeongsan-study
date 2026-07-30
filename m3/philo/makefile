NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRCS = main.c \
	   init_philo.c init_table.c \
	   monitor.c philo_parse.c philo_print.c philo_state.c philo_task_fork.c philo_task.c \
	   time.c cleanup.c mutex_destroy.c

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