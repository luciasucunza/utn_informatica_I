CC = gcc
CFLAGS = -c -g -Wall
LDFLAGS = -lm -g
OBJS = main.o fun.o

ejecutable: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@ 
%.o: %.c main.h
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f ./*.o
	rm -r ejecutable
