main.exe: main.o out_of_bound_exception.o
	g++ main.o out_of_bound_exception.o -o main.exe

main.o: main.cpp matrix3D.h
	g++ -c main.cpp  -o main.o

out_of_bound_exception.o: out_of_bound_exception.h
	g++ -c out_of_bound_exception.cpp -o out_of_bound_exception.o

.PHONY: clean
clean:
	rm -r *.o *.exe
