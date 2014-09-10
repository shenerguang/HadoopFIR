CFLAGS=-o3
CC = arm-linux-gnueabihf-g++

all: clean mapper reducer

mapper:
	$(CC) $(CFLAGS) mapper.cpp -o Mapper
reducer:
	$(CC) $(CFLAGS) reducer.cpp -o Reducer

clean:
	rm -f *.o all

