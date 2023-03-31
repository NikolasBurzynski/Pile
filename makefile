run: main.exe
	./main.exe

main.exe: main.o
	g++ main.o -o main.exe

main.o: main.cpp Heap.h HugeClass.h
	g++ -g -c main.cpp

clean:
	rm -r -f *.o *.exe *.txt