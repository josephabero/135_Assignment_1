all: main.exe

main.exe: main.o
	 g++ -o main.exe main.o

main.o: main.cpp
	 g++ -std=c++11 -c main.cpp

run:
	 ./main.exe

clean:
	 rm main.o main.exe