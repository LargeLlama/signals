all: main.o
	@gcc -o signal.out main.o

main.o: main.c
	@gcc -c main.c

run:
	@./signal.out

clean:
	@rm *.o*
	@rm *.txt
