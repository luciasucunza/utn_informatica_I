CC = gcc
CFLAGS = -c -g -Wall
LDFLAGS = -lm -g
OBJSSERV = Servidor.o FunServidor.o
HEADERSCLIE = Servidor.h

servidor: $(OBJSSERV)
	$(CC) $(OBJSSERV) $(LDFLAGS) -o $@ 
%.o: %.c $(OBJSSERV) $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./*.o
