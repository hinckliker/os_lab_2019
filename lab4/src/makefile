CC=gcc
CFLAGS=-I.

par: parallel_sum.o utils.o utils.h Summary.o
	$(CC) -o par utils.o parallel_sum.o Summary.o  -lpthread  -L   $(CFLAGS)

parallel_sum.o: 
	$(CC) -c parallel_sum.c $(CFLAGS) $(CFLAGS)
utils.o: utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)
  
Summary.o: Summary.h 
	$(CC) -fPIC -c Summary.c -o Summary.o	$(CFLAGS)

z :
	$(CC) -o z Zombie.c 
	
mem : 
	$(CC) -o mem process_memory.c $(CFLAGS)


all : z mem par $(CFLAGS)

clean :
	rm *.o z mem par

res : clean all