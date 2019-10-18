all: main.exe


main.exe:
	 g++ RPS_GUI.cpp GUI_Frame.cpp `wx-config --cxxflags --libs` -o RPS_GUI

run:
	 ./RPS_GUI

clean:
	 rm RPS_GUI
