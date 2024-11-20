NAME = libftso_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
HEADER = -I ./ -I $(MLX42_DIR)/include -I ./includes/libft
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ./includes/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
LIBS = $(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_DIR)/libft.a -framework Cocoa -framework OpenGL -framework IOKit

# Source files
SRCS = 	srcs/so_long.c \
		srcs/getch.c \
		srcs/map.c \
		srcs/render.c \
		srcs/utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to compile the executable
so_long: $(OBJS) $(LIBFT) libmlx
	$(CC) $(CFLAGS) -o so_long $(OBJS) $(LIBFT) $(MLX42) $(LIBS)
	@echo "Executable so_long created."

# Default rule to compile all
all: libmlx $(LIBFT) $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	@$(CC) $(HEADER) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Library $(NAME) created."

# Rule to compile libft
$(LIBFT):
	@make -C ./includes/libft

# Rule to compile MLX42
libmlx:
	@if git submodule status | egrep -q '^[-+]' ; then \
		echo "INFO: Need to reinitialize git submodules"; \
		git submodule update --init; \
	fi
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	make -C $(MLX42_DIR)/build -j4

# Object file compilation rule
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# Clean object files and libraries
clean:
	@rm -f $(OBJS)
	@cd $(LIBFT_DIR) && make clean
	@rm -rf $(MLX42_DIR)/build
	@echo "Object files removed."

# Clean all generated files
fclean: clean
	@rm -f $(NAME) so_long
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)
	@echo "All generated files removed."

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re libmlx $(LIBFT) so_long