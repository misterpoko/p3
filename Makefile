CFLAGS = -g -Wall
CC = g++

compile: main.o DoublyLinkedList.o
	$(CC) $(CFLAGS) -o main main.o DoublyLinkedList.o

DoublyLinkedList:
	$(CC) $(CFLAGS) -c DoublyLinkedList.cpp

main:
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm main
	rm *.o
	
