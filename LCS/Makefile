tests.exe: tests.o LCS.o
	g++ tests.o LCS.o -o tests.exe

tests.o: tests.cpp
	g++ -c tests.cpp -o tests.o

LCS.o: LCS.cpp LCS.h
	g++ -c LCS.cpp -o LCS.o

.PHONY: clean
clean:
	rm -r *.o *.exe