#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/03/05 22:47:28 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -I./inc/ -Wall -Wextra -Werror
SHELL = /bin/sh


LIB_DIR = inc/libft
PTF_DIR = inc/ft_printf
LIB = 	libft.a
PTF =	libftprintf.a

################################################################################
#	ASM
################################################################################
NAME_ASM = cod

#********* -INC
INC_NAME_ASM =	corewar.h
INC_DIR_ASM =	inc
INC_ASM = $(addprefix $(INC_DIR_ASM)/, $(INC_NAME_ASM))

#********* -OBJ
OBJ_DIR_ASM =	asm/obj
OBJ_ASM = $(subst .c,.o,$(subst $(SRC_DIR_ASM)/,$(OBJ_DIR_ASM)/,$(SRC_ASM)))

#********* -SRC
SRC_DIR_ASM =	asm/src
SRC_ASM = $(addprefix $(SRC_DIR_ASM)/, $(SRC_NAME_ASM))
SRC_NAME_ASM =			asm_additionally.c \
						asm_body.c \
						asm_body_list.c \
						asm_error.c \
						asm_header.c \
						asm_main.c \
						asm_search.c \
						asm_args.c \
						both_asml.c

# add .c file ---->


################################################################################
#	RULES
################################################################################

.PHONY: all clean fclean re t

all: $(LIB) $(PTF) $(NAME_ASM)

$(NAME_ASM): $(OBJ_ASM) $(INC_ASM)
	@$(CC) $(CFLAGS) $(OBJ_ASM) -L./$(PTF_DIR) -lftprintf -L./$(LIB_DIR) -lft -o $(NAME_ASM)
	@printf "\033[33m\nYOU TOUCH MY ULA LA! MY DIN DIN DON!!!\ncompiling done.\n\033[0m"

$(LIB):
	

$(PTF):
	

$(OBJ_DIR_ASM)/%.o: $(SRC_DIR_ASM)/%.c | $(OBJ_DIR_ASM)
	@printf "\033[42m  \033[0m"
	@$(CC) -c $(CFLAGS) $? -o $@

$(OBJ_DIR_ASM):
	@mkdir $(OBJ_DIR_ASM)

clean:
	@rm -rf $(OBJ_DIR_ASM)
	@echo "\033[31mСleaning completed\033[0m"
	#@make -C $(LIB_DIR)/ clean fclean 1> /dev/null
	#@make -C $(PTF_DIR)/ clean fclean 1> /dev/null

fclean: clean
	@rm -f $(NAME_ASM)
	@echo "\033[31mPrograms removed\033[0m"
	#@rm -f $(LIB_DIR)/$(LIB) fclean 1> /dev/null
	#@rm -f $(PTF_DIR)/$(PTF) fclean 1> /dev/null

re: fclean recg all

recg:
	@printf "\033[33mRecompiling...\n\033[0m"

t:
	./test/asm test/zork.s

tt: t
	xxd test/zork.cor
