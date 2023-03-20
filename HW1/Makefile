CC=gcc
CFLAGS=-I.
DEPS = hellomake.h
OBJ = 17050111016.o hellofunc.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

17050111016: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)