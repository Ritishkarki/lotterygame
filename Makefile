CC=g++
CFLAGS=-std=c++11

default: main

main: main.o Game.o SlotMachine.o PayoutTable.o 
	$(CC) $(CFLAGS) -o LotteryGame main.o Game.o SlotMachine.o PayoutTable.o

main.o: main.cpp 
	$(CC) -c $(CFLAGS) main.cpp

Game.o: Game.cpp
	$(CC) -c $(CFLAGS) Game.cpp

SlotMachine.o: SlotMachine.cpp
	$(CC) -c $(CFLAGS) SlotMachine.cpp

PayoutTable.o: PayoutTable.cpp
	$(CC) -c $(CFLAGS) PayoutTable.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./LotteryGame
