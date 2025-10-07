# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 11:33:04 by bhajili           #+#    #+#              #
#    Updated: 2025/09/14 11:34:27 by bhajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	theJob
SDIR	=	./
SRCS	=	tests.cpp \
			Account.cpp

ODIR	=	objs/
OBJS	=	$(addprefix $(ODIR), $(SRCS:.cpp=.o))
CMPL	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

$(ODIR)%.o :	$(SDIR)%.cpp
	mkdir -p $(ODIR)
	$(CMPL) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CMPL) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re