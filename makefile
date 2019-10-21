all: main_test

main:
	g++ `wx-config --cxxflags` -o out *.cpp `wx-config --libs`

main_test: StatsPanel.o ButtonPanel.o CompPanel.o RoundCount.o GUI_Frame.o RPS_GUI.o
	 g++ -o RPS_GUI *.o `wx-config --libs`

ButtonPanel.o:
	 g++ `wx-config --cxxflags` -c ButtonPanel.cpp

StatsPanel.o:
	 g++ `wx-config --cxxflags` -c StatsPanel.cpp

CompPanel.o:
	 g++ `wx-config --cxxflags` -c CompPanel.cpp

RoundCount.o:
	 g++ `wx-config --cxxflags` -c RoundCount.cpp

RPS_GUI.o:
	 g++ `wx-config --cxxflags` -c RPS_GUI.cpp

GUI_Frame.o:
	 g++ `wx-config --cxxflags` -c GUI_Frame.cpp

run:
	 ./RPS_GUI

clean:
	 rm RPS_GUI RPS_GUI.o GUI_Frame.o ButtonPanel.o StatsPanel.o CompPanel.o RoundCount.o

hello:
	 g++ -std=c++11 wxHelloWorld.cpp `wx-config --cxxflags --libs` -o wxHello

runHello:
	 ./wxHello

cleanHello:
	 rm wxHello