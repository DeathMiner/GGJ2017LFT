CXX	=	g++

RM	=	rm -f

CXXFLAGS	+=	-Iinclude
CXXFLAGS	+=	-Wall -Wextra -Werror
CXXFLAGS	+=	-g3
CXXFLAGS	+=	-Ofast

LDFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS	+=	-lm

NAME	=	ggj

SRCS	=	main.cpp \
			engine/player.cpp \
			engine/level.cpp \
			engine/grid.cpp

OBJS	=	$(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re