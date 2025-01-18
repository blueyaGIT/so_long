NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := ./includes
SRC_DIRS := ./srcs
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

LIBFT_DIR = $(INC_DIRS)/libft
LIBFT = libft.a
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS = -L$(LIBFT_DIR) -lft
LIBFT_REPO = https://github.com/blueyaGIT/libft.git

MLXFT_DIR = $(INC_DIRS)/MLX42
MLXFT = libmlx42.a
MLXFT_BUILD_DIR = $(INC_DIRS)/mlx_build
MLXFT_LIB = $(MLXFT_BUILD_DIR)/$(MLXFT)
MLXFTFLAGS = -L$(MLXFT_BUILD_DIR) -lmlx42 -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLXFT_REPO = https://github.com/codam-coding-college/MLX42.git

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
NC = \033[0m
CLEAR_LINE = \033[2K\r

# Source files
SRCS = 	main.c \
		getch.c \
		map_collision.c \
		map_read.c \
		map_render.c \
		map_valid.c \
		map_utils.c \
		tile_check.c \
		utils.c

# Object files
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

TOTAL_SRCS = $(words $(SRCS))
CURRENT = 0

# Default rule to compile all
all: init-submodules $(NAME)

-include $(OBJS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)🚧 Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(CYAN)$<$(NC) 🚧"
	@$(CC) $(CFLAGS) -c $< -o $@

# Initialize submodules
init-submodules: init-libft init-mlx

#Initialize libft
init-libft:
	@sleep 0.15
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "$(YELLOW)🚧 Adding LIBFT submodule 🚧$(NC)"; \
		git submodule add $(LIBFT_REPO) $(LIBFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to add libft submodule$(NC)" && exit 1); \
	elif [ -z "$$(ls -A $(LIBFT_DIR) 2>/dev/null)" ]; then \
		echo "$(CYAN)🔄 Updating LIBFT submodule 🔄$(NC)"; \
		git submodule update --init --recursive $(LIBFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to update libft submodule$(NC)" && exit 1); \
	else \
		echo "$(GREEN)✅ LIBFT submodule is already initialized ✅$(NC)"; \
	fi

#Remove submodules
remove-submodules: remove-libft remove-mlx

#Remove libft
remove-libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		git submodule deinit -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(LIBFT_DIR) > /dev/null 2>&1; \
	fi

#Remove MLX42
remove-mlx:
	@if [ -d "$(MLXFT_DIR)" ]; then \
		git submodule deinit -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf ./mlx42 > /dev/null 2>&1; \
	fi

#Rule to compile libft
$(LIBFT_LIB): init-libft
	@if [ ! -f "$(LIBFT_LIB)" ]; then \
		echo "$(CLEAR_LINE)$(YELLOW)🚧 Building LIBFT 🚧$(NC)"; \
		$(MAKE) -C $(LIBFT_DIR); \
	fi

#Initialize MLX42
init-mlx:
	@sleep 0.15
	@if [ ! -d "$(MLXFT_DIR)" ]; then \
		echo "$(YELLOW)🚧 Adding MLX42 submodule 🚧$(NC)"; \
		git submodule add -q $(MLXFT_REPO) $(MLXFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to add MLX42 submodule$(NC)" && exit 1); \
		cd $(MLXFT_DIR) && git checkout 7f95e70415705dcc723f94a2696aba84ed3756ad > /dev/null 2>&1 && cd ../; \
	elif [ -z "$$(ls -A $(MLXFT_DIR) 2>/dev/null)" ]; then \
		echo "$(CYAN)🔄 Updating MLX42 submodule 🔄$(NC)"; \
		git submodule update --init --recursive -q $(MLXFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to update MLX42 submodule$(NC)" && exit 1); \
		cd $(MLXFT_DIR) && git checkout 7f95e70415705dcc723f94a2696aba84ed3756ad > /dev/null 2>&1 && cd ../; \
	else \
		echo "$(GREEN)✅ MLX42 submodule is already initialized ✅$(NC)"; \
	fi

#Rule to compile MLX42
$(MLXFT_LIB): init-mlx
	@cd $(MLXFT_DIR) && git checkout 7f95e70415705dcc723f94a2696aba84ed3756ad 2>/dev/null
	@if [ ! -f "$(MLXFT_LIB)" ]; then \
		echo "$(CLEAR_LINE)$(YELLOW)🚧 Building MLX42 🚧$(NC)"; \
		mkdir -p $(MLXFT_BUILD_DIR); \
		cmake -S $(MLXFT_DIR) -B $(MLXFT_BUILD_DIR) > /dev/null 2>&1 && \
		cmake --build $(MLXFT_BUILD_DIR) --parallel > /dev/null 2>&1 || \
		(echo "$(RED)Failed to build MLX42$(NC)" && exit 1); \
	fi


#Rule to compile program
$(NAME): init-submodules $(LIBFT_LIB) $(MLXFT_LIB) $(OBJS)
	@echo "$(CLEAR_LINE)$(YELLOW)🚧 Building SO_LONG 🚧$(NC)"
	@$(CC) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(MLXFTFLAGS)
	@echo "$(CLEAR_LINE)$(GREEN)✅ Done Compiling ✅$(NC)"

# Clean object files and libraries
clean: remove-submodules
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@rm -rf $(MLXFT_DIR)
	@rm -rf $(LIBFT_DIR)

# Clean all generated files
fclean: clean
	@echo "$(YELLOW)🚧 Cleaning 🚧$(NC)"
	@sleep 0.15
	@printf "$(RED)🧹 Cleaning in Progress 🧹$(NC)\n"
	@sleep 0.15
	@printf "$(YELLOW)🛁 Scrubbing Code 🛁$(NC)\n"
	@sleep 0.15
	@printf "$(CYAN)🧽 Polishing Project 🧽$(NC)\n"
	@sleep 0.15
	@printf "$(MAGENTA)🧴 Tidying Up 🧴$(NC)\n"
	@sleep 0.15
	@printf "$(GREEN)✅ Done Cleaning ✅$(NC)\n"
	@rm -rf $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re libft mlx init-submodules remove-submodules
