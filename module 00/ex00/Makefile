CC = g++
CFLAGS = -Wall -Wextra -Werror
TARGET = megaphone

all: $(TARGET)

$(TARGET): megaphone.cpp
	$(CC) $(CFLAGS) -o $(TARGET) megaphone.cpp

megaphone.o: megaphone.cpp
	$(CC) $(CFLAGS) -c megaphone.cpp

clean:
	rm -f $(TARGET) *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
