objects = $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.c,%.o,$(wildcard commands/*.c))
CC = gcc
CFLAGS = -iquote include -iquote commands/include

expenses : $(objects)
		   $(CC) -o bin/expenses $(objects)

$(objects) : %.o : %.c
	   $(CC) -c $(CFLAGS) $< -o $@

.PHONY : rebuild
rebuild : clean
	make
.PHONY : clean
clean  :
		 rm bin/expenses $(objects)