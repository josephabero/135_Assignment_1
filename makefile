all: main.exe

main.exe: external.o internal.o
	 g++ -o RPS_GUI *.o `wx-config --libs`

external.o:
	g++ `wx-config --cxxflags` -c *.cpp

internal.o:
	g++ `wx-config --cxxflags` -c game/*.cpp

run:
	 ./RPS_GUI

clean:
	 rm RPS_GUI *.o

hello:
	 g++ -std=c++11 wxHelloWorld.cpp `wx-config --cxxflags --libs` -o wxHello

runHello:
	 ./wxHello

cleanHello:
	 rm wxHello
