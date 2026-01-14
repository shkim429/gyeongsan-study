NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC) -g
RM = rm -rf
SRCS = push_swap.c \
	   sort.c sort_utils.c radix_sort_utils.c \
	   create_stack.c stack_ops.c stack_ops_utils.c \
	   input_valid.c input_valid_utils.c \
	   error.c free_res_utils.c

OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS_PATH = -L. \
            -L./ft_libft
LIBS_DIR_PATH = ./ft_libft
LIBS = -lftprintfgnl

INC = -I. \
	  -I./ft_libft/include

MAIN_EXE = push_swap
	
all : $(MAIN_EXE)

$(LIBPRINTFGNL_A) :
	make -C $(LIBS_DIR_PATH)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_FILES)
	make -C $(LIBS_DIR_PATH)
	ar -rcs $(NAME) $(OBJS_FILES)

$(MAIN_EXE) : $(NAME)
	$(CC) $(CFLAGS) $(NAME) $(LIBS_PATH) $(LIBS) -o $(MAIN_EXE)
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ_DIR) $(MAIN_EXE)
	make -C $(LIBS_DIR_PATH) clean


fclean : clean
	$(RM) $(NAME) $(MAIN_EXE)
	make -C $(LIBS_DIR_PATH) fclean


re : fclean all
	
.PHONY : all clean fclean re