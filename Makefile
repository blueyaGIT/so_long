NAME = libftso_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF_DIR = ./includes/printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
MLX42_DIR = ./includes/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
LIBS = $(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_DIR)/libft.a

# Source files
SRCS = 	srcs/so_long.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to compile the executable
so_long: $(OBJS) $(LIBFT) $(LIBFTPRINTF) libmlx
	$(CC) $(CFLAGS) -o so_long $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	@echo "Executable so_long created."

# Default rule to compile all
all: $(LIBFT) $(LIBFTPRINTF) $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

# Rule to compile libft
$(LIBFT):
	@cd $(LIBFT_DIR) && make

# Rule to compile libftprintf
$(LIBFTPRINTF): $(LIBFT)
	@cd $(LIBFTPRINTF_DIR) && make

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
	@cd $(LIBFTPRINTF_DIR) && make clean
	@rm -rf $(MLX42_DIR)/build
	@echo "Object files removed."

# Clean all generated files
fclean: clean
	@rm -f $(NAME) so_long
	@cd $(LIBFT_DIR) && make fclean
	@cd $(LIBFTPRINTF_DIR) && make fclean
	@rm -f $(NAME)
	@echo "All generated files removed."

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re libmlx $(LIBFT) $(LIBFTPRINTF)