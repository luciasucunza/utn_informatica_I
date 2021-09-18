CC = gcc
CFLAGS = -c -g -Wall
LDFLAGS = -lm -g
OBJSCLIE = Cliente.o FunCliente.o
HEADERS = Cliente.h

cliente: $(OBJSCLIE)
	$(CC) $(OBJSCLIE) $(LDFLAGS) -o $@ 
%.o: %.c $(OBJSCLIE) $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./*.o
