all: main.exe

# main.exe: main.o
# 	 g++ -o main.exe main.o

main.exe: main.cpp user.hpp game.hpp computer.hpp DumbComputer.hpp SmartComputer.hpp Score.hpp FactoryComputer.hpp
	 g++ -std=c++11 main.cpp  game.cpp user.cpp DumbComputer.cpp SmartComputer.cpp Score.cpp FactoryComputer.cpp

run:
	 ./main.exe

clean:
	 rm main.o computer.o game.o player.o user.o
