CFLAGS = -g -I../include/ -std=c99 -Wall 
CC=gcc
OBJS =  obj/edge_detect.o \
	    obj/pgm.o \
	    obj/deriche.o \
	    obj/alloc.o 

INCS = ../include/common.h
PROG = deriche
SRCDIR = ../src/

float: run 
	
	
deriche : $(OBJS) $(INCS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) -lm

obj/edge_detect.o : $(SRCDIR)edge_detect.c $(INCS) 
	$(CC) $(CFLAGS) -c -o obj/edge_detect.o $(SRCDIR)edge_detect.c
	
obj/pgm.o : $(SRCDIR)pgm.c $(INCS)
	$(CC) $(CFLAGS) -c -o obj/pgm.o $(SRCDIR)pgm.c

obj/deriche.o : $(SRCDIR)deriche.c $(INCS)
	$(CC) $(CFLAGS) -c -o obj/deriche.o $(SRCDIR)deriche.c
	
obj/alloc.o : $(SRCDIR)alloc.c $(INCS)
	$(CC) $(CFLAGS) -c -o obj/alloc.o $(SRCDIR)alloc.c
	
	
run: $(PROG)
	#./$(PROG) ../data/satellite.pgm ./deriche-satellite.pgm float_slow
	#./$(PROG) ../data/satellite.pgm ./deriche-satellite.pgm fixed_slow
	#./$(PROG) ../data/satellite.pgm ./deriche-satellite.pgm fixed_fast
	#./$(PROG) ../data/satellite.pgm ./deriche-satellite.pgm fixed_array
	./$(PROG) ../data/satellite.pgm ./deriche-satellite.pgm fixed_short
	
clean:
	rm obj/* $(PROG)
