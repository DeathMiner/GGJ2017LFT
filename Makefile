CC	=	g++

RM	=	rm -f

CFLAGS	+=	-Iinclude
CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-g3
CFLAGS	+=	-Ofast

LDFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS	+=	-lm

NAME	=	ggj

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re