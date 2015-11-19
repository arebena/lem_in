#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arebena <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 22:06:46 by arebena           #+#    #+#              #
#    Updated: 2015/11/19 14:45:50 by arebena          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	lem-in

SRC =	GNL/get_next_line.c\
		lem_in.c\
		tools_map.c\
		tools_room.c\
		tools_link.c\
		info_map.c\

SRCS = $(addprefix srcs/,$(SRC))
SRCO =	$(addprefix obj/, $(notdir $(SRC:.c=.o)))

FLG =	-Wall -Wextra -Werror
LIBS =	-L srcs/Libft/ -lft
LIBFT =	srcs/Libft/

LI = 	\033[1;33;35m\tlem_in \033[0m
LIB = 	\033[1;33;33m \tLIB \033[0m
DONE = 	\033[1;33;32mdone\033[0m
CREAT = \033[1;33;34m(creat)\033[0m
DEL = 	\033[1;33;31m(del)\033[0m
RE = 	\033[1;33;36m(re)\033[0m
.o = 	\033[1;33;31m.o \033[0m
.a = 	\033[1;33;31m.a \033[0m
.exe =	\033[1;33;31m.exe \033[0m

$(NAME): 
	@make -C $(LIBFT)
	@echo "$(RE)$(LIB)$(.a) \033[33;37m------\033[0m $(DONE)"
	@echo "\033[1;31;30m###########################\033[0m"
	@gcc $(FLG) -I $(LIBFT) -c $(SRCS)
	@mkdir -p obj
	@mv $(notdir $(SRCO)) obj
	@echo "$(CREAT)$(LI)$(.o) \033[33;37m---\033[0m $(DONE)"
	@gcc $(FLG) -o $(NAME) $(SRCO) $(LIBS)
	@chmod 755 $(NAME)
	@echo "$(CREAT)$(LI)$(.exe) \033[33;37m-\033[0m $(DONE)"

all:$(NAME)

clean:
	@rm -rf obj
	@make -C $(LIBFT) clean
	@echo "$(DEL)$(LI)$(.o) \033[33;37m---\033[0m $(DONE)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(DEL)$(LI)$(.exe) \033[33;37m-\033[0m $(DONE)"
	@echo "\033[1;38;30m###########################\033[0m"

re:fclean all

rec:re
	@make clean
