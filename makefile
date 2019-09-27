all: main.exe

# main.exe: main.o
# 	 g++ -o main.exe main.o

main.exe: main.cpp user.hpp user.hpp player.hpp computer.hpp
	 g++ -std=c++11 main.cpp  game.cpp user.cpp

run:
	 ./main.exe

clean:
	 rm main.o computer.o game.o player.o user.o
