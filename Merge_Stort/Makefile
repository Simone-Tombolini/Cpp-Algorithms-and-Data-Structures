Main.exe: Main.o 
	g++ Main.o -o Main.exe

Main.o: Main.cpp MergeSort.h
	g++ -c Main.cpp -o Main.o

.PHONY: clean
clean:
	rm -r *.o *.exe