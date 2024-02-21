NAME = cub3d
CC = cc 
FLAGS =   -Wall -Wextra -Werror  -g -fsanitize=address
LIBFT_A = libft/libft.a
LIBFT = libft/
MLX = MLX/libmlx42.a
FLAG_MLX = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
INCLUDE = -I/Users/akaabi/.brew/Cellar/glfw/3.3.9/include/GLFW
LIB = -L/Users/akaabi/.brew/Cellar/glfw/3.3.9/lib
SRC = main.c check_map.c cub3d_utils.c map.c walls.c inside_map.c resize_map.c direction_parc.c fill_struct.c rgb.c free.c execution.c data_fill.c player_movement.c raycast.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c cub3d.h libft/libft.h
	$(CC) $(FLAGS)  $(include) -c $< -o $@

$(NAME) : $(OBJ) 
	@make -s -C $(LIBFT) 
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) $(MLX) $(LIB) $(FLAG_MLX) -o $(NAME)


clean :
	@rm -rf libft/*.o
	@rm -rf libftprintf/*.o
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(LIBFT_A)
	@rm -rf $(NAME)

re : clean fclean all