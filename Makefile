# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque   <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 22:38:06 by aroque            #+#    #+#              #
#    Updated: 2020/11/04 21:55:49 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRC		=	ft_strlen.s	\
			ft_strcpy.s	\
			ft_strcmp.s	\
			ft_write.s	\
			ft_read.s	\
			ft_strdup.s

SRCBONUS =	ft_list_push_front_bonus.s	\
			ft_list_size_bonus.s		\
			ft_list_sort_bonus.s

OBJ_DIR	=	./build
OBJ		=	$(patsubst %.s, ${OBJ_DIR}/%.o, ${SRC})
OBJBONUS=	$(patsubst ${SRC_DIR}/%.s, ${OBJ_DIR}/%.o, ${SRCBONUS})

INCLUDE	=	./include

ASM			=	nasm
ASM_FLAGS	=	-felf64

AR_FLAGS	=	rcs

CC			=	clang
CC_FLAGS	=	-Wall			\
 				-Wextra			\
 				-Werror			\
				-I${INCLUDE}	\
 				-L.				\
 				-lasm

TEST_DIR	=	./tests
TEST		=	${TEST_DIR}/main.c
BIN			=	${TEST_DIR}/main

TEST_BONUS	=	${TEST_DIR}/main_bonus.c
EXEC_BONUS	=	${TEST_DIR}/mainbonus

vpath %.s src
vpath %.h include

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(AR_FLAGS) $@ $^

${OBJ_DIR}/%.o: %.s
	mkdir -p $(OBJ_DIR)
	$(ASM) $(ASM_FLAGS)	$< -o $@

test: $(TEST)
	$(CC) $< $(CC_FLAGS) -o $(BIN)
	$(BIN)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all
