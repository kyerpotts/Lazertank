# Makefile Variables
CC = gcc
EXEC = laserTank
CFLAGS = -Wall -ansi -pedantic
OBJ = laser_tank.o canvas.o boundaries.o stage.o action.o newSleep.o

# Add FANCY to the CFLAGS and recompile the program
ifdef FANCY
CFLAGS += -D FANCY
FANCY : clean $(EXEC)
endif

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

laser_tank.o : laser_tank.c
	$(CC) $(CFLAGS) laser_tank.c -c

action.o : action.c
	$(CC) $(CFLAGS) action.c -c

canvas.o : canvas.c
	$(CC) $(CFLAGS) canvas.c -c

boundaries.o : boundaries.c
	$(CC) $(CFLAGS) boundaries.c -c

newSleep.o : newSleep.c
	$(CC) $(CFLAGS) newSleep.c -c

stage.o : stage.c
	$(CC) $(CFLAGS) stage.c -c

clean:
	rm -f $(EXEC) $(OBJ)
