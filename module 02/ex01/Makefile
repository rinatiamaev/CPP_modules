CC = c++
CFLAGS = -Wall -Wextra -Werror
TARGET = Towards

SRCS = main.cpp Fixed.cpp
INCLUDES = Fixed.hpp

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.cpp=.o))

all: $(TARGET)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(TARGET): $(OBJSDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJSDIR)/%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
