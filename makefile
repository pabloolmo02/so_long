INCS = -IMLX42/include
LIBDIR = -LMLX42 -L/Users/pgonzal2/.brew/Cellar/glfw/3.4/lib
LIB = -lmlx42 -ldl -lglfw

LIBFT_DIR         = libs/libft/
LIBFT             = libft.a
MLX42_DIR         = ./libs/MLX42
GNL_DIR           = ./libs/get_next_line
NAME              = so_long
CC                = gcc
CFLAGS            = -Wall -Werror -Wextra -I. -Iincludes -g -I$(MLX42_DIR)/include -I$(GNL_DIR)
MLX_FLAGS         = -ldl -pthread -lm -lglfw
RM                = rm -rf

SRC_DIR           = srcs/
OBJ_DIR           = obj/

# Listado de archivos fuente por directorio
UTILS_SRC         = utils/errors.c utils/utils.c
MAP_SRC           = map/map_checker.c map/map_init.c
MOVES_SRC         = movements/controls.c movements/moves.c
GRAPHICS_SRC      = graphics/textures.c
MAIN_SRC          = main.c

# Archivos de get_next_line
GNL_SRC           = get_next_line.c get_next_line_utils.c

# Combinar todos los archivos fuente
FILES_SRC         = $(UTILS_SRC) $(MAP_SRC) $(MOVES_SRC) $(GRAPHICS_SRC) $(MAIN_SRC)

# Generar rutas completas
SRC               = $(addprefix $(SRC_DIR),$(FILES_SRC))
GNL_FULL_SRC      = $(addprefix $(GNL_DIR)/,$(GNL_SRC))

# Generar rutas para los archivos objeto
OBJ_SRC           = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
GNL_OBJ           = $(GNL_FULL_SRC:%.c=$(OBJ_DIR)/%.o)

# Crear directorios para objetos
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar get_next_line
$(OBJ_DIR)/$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ_SRC) $(GNL_OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(MAKE) -s -C libs/ft_printf
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@$(MAKE) -C $(MLX42_DIR)/build
	$(CC) $(OBJ_SRC) $(GNL_OBJ) -I$(MLX42_DIR)/include -L$(MLX42_DIR)/build -lmlx42 $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -L./libs/ft_printf -lftprintf -o $@

clean:
	@$(RM) $(OBJ_DIR)
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C ./libs/ft_printf fclean
	@$(MAKE) -C $(MLX42_DIR)/build clean

re: fclean all

.PHONY: all clean fclean re