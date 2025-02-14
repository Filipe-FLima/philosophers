# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 16:01:48 by filipe            #+#    #+#              #
#    Updated: 2025/02/13 21:19:19 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address

INCLUDE = includes/
OBJ_DIR = objs/

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m

SRCS= srcs/errors_handling.c srcs/init_data.c srcs/main.c \
		srcs/manager.c srcs/routine.c srcs/start_simulation.c \
			srcs/utils.c srcs/free.c
			
OBJS= $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(BLUE)Compiling philo program...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDE) -o $(NAME)
	@echo "$(GREEN)philo  [OK]$(RESET)\n"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "\n$(GREEN)Object files have been removed   [OK]$(RESET)\n"; \
	fi
	@rm -rf $(OBJ_DIR);

fclean: clean
	@rm -f $(NAME)
	@echo "\n$(GREEN)Executable file has been removed [OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re