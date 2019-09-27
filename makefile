all: main.exe

# main.exe: main.o
# 	 g++ -o main.exe main.o

main.exe: main.cpp player.hpp user.hpp
	 g++ -std=c++11 main.cpp computer.cpp game.cpp player.cpp user.cpp

run:
	 ./main.exe

clean:
	 rm main.o computer.o game.o player.o user.o