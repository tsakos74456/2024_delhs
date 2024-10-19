# compiler
CC = gcc 

# flags
# CFLAGS = -Wall -Werror -g

# objected files
OBJS = main.o list.o

EXEC = miris

all : $(EXEC)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

list.o : list.c
	$(CC) $(CFLAGS) -c list.c -o list.o

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC) -i list.txt -o output

clean :
	rm -f $(OBJS) $(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC) -i list.txt -o output

remove:
	rm -f $(OBJS) $(EXEC)