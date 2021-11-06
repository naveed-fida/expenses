objects = $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.c,%.o,$(wildcard commands/*.c))
CC = gcc
CFLAGS = -iquote include

expenses : $(objects)
		   $(CC) -o bin/expenses $(objects)

$(objects) : %.o : %.c
	   $(CC) -c $(CFLAGS) $< -o $@

.PHONY : clean
clean  :
		 rm bin/expenses $(objects)