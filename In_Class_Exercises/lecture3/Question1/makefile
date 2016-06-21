question1:question1.o conversions.o
	g++ -Wall -g conversions.o question1.o -o  question1

question1.o: question1.cpp conversions.h
	g++ -Wall -g -c question1.cpp

conversions.o: conversions.cpp conversions.h
	g++ -Wall -g -c conversions.cpp
