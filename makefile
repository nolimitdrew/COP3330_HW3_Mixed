main_executable: main.o mixed.o
	g++ -g -o main main.o mixed.o
	chmod 755 main

mixed.o: mixed.cpp mixed.h
	g++ -g -c mixed.cpp 

main.o: main.cpp mixed.h
	g++ -g -c main.cpp    

clean:
	rm -f *.o