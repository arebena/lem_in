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
		lem_tools.c\
		lem_proc.c\
		lem_matrix.c\
		tools_map.c\
		tools_room.c\
		tools_link.c\
		info_map.c\

SRCS = $(addprefix srcs/,$(SRC))
SRCO =	$(addprefix obj/, $(notdir $(SRC:.c=.o)))

FLG =	-Wall -Wextra -Werror
LIBS =	-L srcs/Libft/ -lft
LIBFT =	srcs/Libft
HEADS = -I srcs/Libft/srcs/ -I srcs/GNL/ -I includes/

$(NAME):
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@make --no-print-directory -C $(LIBFT)
	@echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo -ne "Creating LEM_IN Object files..."
	@gcc $(FLG) $(HEADS) -c $(SRCS)
	@mkdir -p obj
	@mv $(notdir $(SRCO)) obj
	@number=1 ; while [[ $$number -le 31 ]] ; do \
		echo -ne "\b" ; \
		((number = number + 1)) ; \
	done
	@echo "Object files successfully compiled	"
	@echo -ne "Creating LEM_IN..."
	@gcc $(FLG) -o $(NAME) $(SRCO) $(LIBS)
	@chmod 755 $(NAME)
	@mv $(NAME).exe $(NAME)
	@number=1 ; while [[ $$number -le 18 ]] ; do \
		echo -ne "\b" ; \
		((number = number + 1)) ; \
	done
	@echo  "  ====== LEM_IN created ======"
	@echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

all:$(NAME)

Mclean:
	@rm -rf obj
	@echo "|| LEM_IN object files deleted"

Fclean:Mclean
	@rm -rf $(NAME)
	@echo "|| LEM_IN deleted"
	@make --no-print-directory -C $(LIBFT) fclean

clean:
	@rm -rf obj
	@echo "|| LEM_IN object files deleted"

fclean:clean
	@rm -rf $(NAME)
	@echo "|| LEM_IN deleted"

re: fclean all

rec: fclean all
	@rm -rf obj
	@echo "|| LEM_IN object files deleted"

RE: Fclean all
