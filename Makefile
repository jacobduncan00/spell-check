run: main.o Dictionary.o HashTable.o
	g++ -o run main.o Dictionary.o HashTable.o

Dictionary.o: Dictionary.cpp
	g++ -c Dictionary.cpp -std=c++11

HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm *.o
	rm run
