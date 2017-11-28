# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mseinic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/14 11:35:32 by mseinic           #+#    #+#              #
#    Updated: 2017/11/28 15:50:42 by mseinic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------MODIF--------------------#
NAME := malloc_test.exe
SRC_LIST = main malloc manage_alloc new_page
#----------------MODIF--------------------#

#----------------STD--------------------#
COMPILER := clang
SRC_PATH := srcs/
HDR_PATH := includes/
CACHE_PATH := cache/
INCF = -I $(HDR_PATH)

CFLAGS = -g -Wextra -Wall $(INCF)

#----------------STD--------------------#

#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#
SRC = $(addprefix $(SRC_PATH),$(addsuffix .c,$(SRC_LIST)))
OBJ = $(addprefix $(CACHE_PATH),$(addsuffix .o,$(SRC_LIST)))
#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#

#-----------------COLORS------------------#
#-------B = Bolt---------#
#-------I = Intense------#
#-------U = Underline----#
Green	:= "\033[0;32m"
Red		:= "\033[1;91m"
Yellow	:= "\033[0;33m"
CYAN	:= "\033[1;36m"
YELLOW	:= "\033[1;33m"
END 	:= "\033[0m"
#-----------------COLORS------------------#

all: $(NAME)

$(NAME): $(OBJ)
		@echo $(Yellow) " Compiling --> $@ <-- with $(CFLAGS) " $(END)
		@$(COMPILER) $(OBJ) -o $@ $(INCF)
		@echo $(Green) " !!! Ready !!!" $(END)

$(CACHE_PATH)%.o:$(SRC_PATH)%.c
		@mkdir -p $(CACHE_PATH)
		@echo $(Green) "Creating $(NAME) : $@ with $< " $(END);
		@$(COMPILER) $(CFLAGS) -o $@ -c $<

%.c:
	@echo $(Red) "Missing file : $@" $(END)
clean:
		@/bin/rm -rf $(CACHE_PATH)
		@echo $(Red) "Deleting ---->>>> $(CACHE_PATH)" $(END)
fclean: clean
		@/bin/rm -rf $(NAME)
		@echo $(Red) "Deleting ---->>>> $(NAME)" $(END)
re: fclean all

norme:
		@echo $(Red)
		@norminette $(SRC) $(HDR_PATH) | grep -v  Norme -B1 || true
		@echo $(END)

test:
		@echo $(YELLOW)"Files :\n\033[0;33m"$(HDR_PATH)
		@echo $(BLUE)"Objects :\n\033[0;34m"$(OBJ)
		@echo $(CYAN)"Sources :\n\033[0;36m"$(SRC)

.PHONY: all clean fclean re
