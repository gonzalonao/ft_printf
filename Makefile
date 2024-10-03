# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:55:07 by glopez-c          #+#    #+#              #
#    Updated: 2024/10/03 20:53:41 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs

RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_PATH = ./sources/
OBJ_PATH = ./objects/

SRC = ft_printf ft_printchar_fd ft_printnbr_base_fd \
	ft_printnbr_fd ft_printstr_fd
    
SRCC = $(addsuffix .c, ${SRC})
SRCS = $(addprefix $(SRC_PATH), $(SRCC))

OBJ = $(SRCC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INC = -I ./includes/

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

# Animation

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@printf "$(YELLOW)Compiling $<...$(RESET)\n"
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@
	@printf "$(GREEN)Compiled $< successfully!$(RESET)\n"

all:  ${NAME}

$(NAME): ${OBJS}
	@printf "$(BLUE)Creating library $@...$(RESET)\n"
	@${AR} ${NAME} ${OBJS}
	@printf "$(GREEN)Library $@ created successfully!$(RESET)\n"

bonus:  ${BOBJS}
	@printf "$(BLUE)Creating bonus archive $@...$(RESET)\n"
	@${AR} ${NAME} ${BOBJS}
	@printf "$(GREEN)Bonus library $@ created successfully!$(RESET)\n"

clean: 
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@${RM} ${OBJS} ${BOBJS}
	@printf "$(GREEN)Object files cleaned!$(RESET)\n"

fclean: clean
	@printf "$(RED)Cleaning Library...$(RESET)\n"
	@${RM} ${NAME}
	@printf "$(GREEN)Library cleaned!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus