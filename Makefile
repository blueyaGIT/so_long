NAME = libftso_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF_DIR = ./includes/printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
# MLX42_DIR = ./includes/MLX42/include/MLX42
# MLX42 = $(MLX42_DIR)/MLX42.a

# Source files
SRCS = 	srcs/so_long.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Rule to compile the executable
so_long: $(OBJS) $(LIBFT) $(LIBFTPRINTF)
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

# $(MLX42): $(LIBFTPRINTF)
# 	@cd $(MLX42_DIR) && make

# Object file compilation rule
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# Clean object files and libraries
clean:
	@rm -f $(OBJS)
	@cd $(LIBFT_DIR) && make clean
	@cd $(LIBFTPRINTF_DIR) && make clean
#	@cd $(MLX42_DIR) && make clean
	@echo "Object files removed."

# Clean all generated files
fclean: clean
	@rm -f $(NAME) push_swap
	@cd $(LIBFT_DIR) && make fclean
	@cd $(LIBFTPRINTF_DIR) && make fclean
#	@cd $(MLX42_DIR) && make fclean
	@echo "All generated files removed."

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re $(LIBFT) $(LIBFTPRINTF)