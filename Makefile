CC  = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
INC = $(wildcard *.h)

all : exec

%.o : %.c $(INC)
	$(CC) -c $< -o $@
   
exec : $(OBJ)
	$(CC) $^ -o $@
	
clean :
	rm -f *.o
	rm -f exec
	
