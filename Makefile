# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque   <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 22:38:06 by aroque            #+#    #+#              #
#    Updated: 2020/11/06 00:42:48 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRC		=	ft_strlen.s	\
			ft_strcpy.s	\
			ft_strcmp.s	\
			ft_write.s	\
			ft_read.s	\
			ft_strdup.s

SRC_BONUS =	ft_list_push_front_bonus.s	\
			ft_list_size_bonus.s		\
			ft_list_sort_bonus.s

OBJ_DIR	=	./build
OBJ		=	$(patsubst %.s, ${OBJ_DIR}/%.o, ${SRC})
OBJ_BONUS	=	$(patsubst %.s, ${OBJ_DIR}/%.o, ${SRC_BONUS})

INCLUDE	=	./include
HEADER = 	${INCLUDE}/libasm.h

ASM			=	nasm
ASM_FLAGS	=	-felf64

AR_FLAGS	=	rcs

CC			=	clang
CC_FLAGS	=	-Wall			\
 				-Wextra			\
 				-Werror			\
 				-g				\
				-I${INCLUDE}	\
 				-L.				\
 				-lasm

TEST_DIR	=	./tests
TEST		=	${TEST_DIR}/main.c
BIN			=	${TEST_DIR}/main


ifdef BONUS
  	OBJ += $(OBJ_BONUS)
endif
	
vpath %.s src
vpath %.h include


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(AR_FLAGS) $@ $^

${OBJ_DIR}/%.o: %.s
	mkdir -p $(OBJ_DIR)
	$(ASM) $(ASM_FLAGS)	$< -o $@

bonus:
	$(MAKE) BONUS=1 all

test: $(TEST) $(NAME)
	$(CC) $< $(CC_FLAGS) -o $(BIN)
	$(BIN)

test_bonus: $(TEST) $(NAME) bonus
	$(CC) $< $(CC_FLAGS) -D BONUS=1 -o $(BIN)
	$(BIN)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
