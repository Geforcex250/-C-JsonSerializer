SRC =	unit-tests/main.cpp \
	JSONDocument.cpp

NAME =	test-me

all: $(NAME)

$(NAME):
	g++ $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

clean:	fclean

re:	fclean $(NAME)
