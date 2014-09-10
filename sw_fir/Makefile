CFLAGS=-o3
CC = arm-linux-gnueabihf-g++

all: clean mapper reducer

mapper: fir.o
	$(CC) $(CFLAGS) fir.o mapper.cpp -o Mapper
reducer:
	$(CC) $(CFLAGS) reducer.cpp -o Reducer
fir.o:
	$(CC) -c fir.c
single: fir.o
	$(CC) $(CFLAGS) fir.o single_fir.c -o Single
	


clean:
	rm -f *.o all

