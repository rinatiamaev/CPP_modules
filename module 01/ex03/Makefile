CC = g++
CFLAGS = -Wall -Wextra -Werror
TARGET = violence

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
INCLUDES = Weapon.hpp HumanA.hpp HumanB.hpp

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.cpp=.o))

all: $(TARGET)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(TARGET): $(OBJSDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJSDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
