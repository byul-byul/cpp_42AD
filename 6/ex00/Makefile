NAME	=	convert
TEST_NAME	=	tests_ScalarConverter
SDIR	=	./
SRCS	=	main.cpp \
			ScalarConverter.cpp
TEST_SRCS	=	tests_ScalarConverter.cpp \
			ScalarConverter.cpp

ODIR	=	objs/
OBJS	=	$(addprefix $(ODIR), $(SRCS:.cpp=.o))
TEST_OBJS	=	$(addprefix $(ODIR), $(TEST_SRCS:.cpp=.o))
CMPL	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

$(ODIR)%.o :	$(SDIR)%.cpp
	mkdir -p $(ODIR)
	$(CMPL) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CMPL) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CMPL) $(FLAGS) -o $(TEST_NAME) $(TEST_OBJS)

test: $(TEST_NAME)
	./$(TEST_NAME)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
