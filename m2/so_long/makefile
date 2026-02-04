NAME = so_long
CC = cc
CFLAGS = $(INC) -g
RM = rm -rf
SRCS = so_long.c error.c map_validate.c load_res.c

OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS_PATH = -L. \
			-L./ft_libft \
			-Lminilibx-linux

LIBS_DIR_PATH = ./ft_libft 
MLX_DIR_PATH = ./minilibx-linux

MLX_A = $(MLX_DIR_PATH)/libmlx.a

LIBS = -lftprintfgnl -lmlx -lXext -lX11

INC = -I. \
	  -I./ft_libft/include \
	  -I./minilibx-linux

all : $(NAME)

$(MLX_A) :
	make -C $(MLX_DIR_PATH)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_FILES) $(MLX_A)
	make -C $(LIBS_DIR_PATH)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(MLX_A) $(LIBS_PATH) $(LIBS) -o $(NAME)

clean :
	$(RM) $(OBJ_DIR)
	make -C $(LIBS_DIR_PATH) clean


fclean : clean
	$(RM) $(NAME)
	make -C $(LIBS_DIR_PATH) fclean


re : fclean all
	
.PHONY : all clean fclean re