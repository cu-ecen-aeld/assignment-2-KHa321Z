CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -Werror -g

all: writer

writer.o: writer.c
		  $(CC) $(CFLAGS) -c writer.c
		  
writer:	writer.o
		$(CC) $(CFLAGS) -o writer writer.o
		
clean: 
		rm -f writer writer.o
		
.PHONY: all clean
