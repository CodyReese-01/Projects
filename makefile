all: project

project: Reese_Cody_Project03.o Project03.o
	g++ Reese_Cody_Project03.o Project03.o -o project
	
Reese_Cody_Project03.o: Reese_Cody_Project03.cpp
	g++ -c Reese_Cody_Project03.cpp
	
Project03.o: Project03.cpp Project03.h
	g++ -c Project03.cpp
	
clean:
	rm *.o project