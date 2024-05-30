CC=gcc

CFLAGS=-Wall 

LIBS= -lgsl

OBJ= main.o Calculate_force.o External_load.o Initialize_masses_position.o Initialize_masses_velocity.o Build_neigh_list.o Save_force.o Update_position.o Update_velocity.o Define_bc.o
LDFLAGS=-lm 


# phony targets will always be remade, so a file named "clean"

# won't prevent the clean target from running

.PHONY: all clean test


all: main



main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS)



clean:
	rm -f main *.o



test: main
	./main

