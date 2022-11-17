main.exe: main.o LCS.o
	g++ main.o LCS.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

LCS.o: LCS.cpp
	g++ -c LCS.cpp -o LCS.o

.PHONY: clean
clean:
	rm -r *.o *.exe