/*

Author: Eugene Valassakis
Created Date: 9 oct 2015

 This is the statistics implementation file,
 It has the definitions of the average functions and the standard deviations functions
for 2, 3 and 4 input values. */

#include <iostream>
#include <cmath>
#include "statistics.h"

using namespace std;

/*Define the averages functions*/

double average(double value1, double value2){

	double average = (value1 +value2) /2 ;
	return average;
}

double average(double value1, double value2, double value3){

	double average = (value1 +value2+value3) /3 ;
	return average;
}

double average(double value1, double value2, double value3,double value4){

	double average = (value1 +value2+value3+value4) /4 ;
	return average;
}

/*END of average functions definitions*/


/*Define the standard deviation functions */

double stdev(double value1, double value2, double average){

	double stdev = sqrt((pow(value1-average,2)+pow(value2-average,2))/2);
	return stdev;

}



double stdev(double value1, double value2,double value3, double average){

	double stdev = sqrt((pow(value1-average,2)+pow(value2-average,2)+pow(value3-average,2))/3);
	return stdev;

}


double stdev(double value1, double value2,double value3, double value4, double average){

	double stdev = sqrt((pow(value1-average,2)+pow(value2-average,2)+pow(value3-average,2)+pow(value4-average,2))/4);
	return stdev;

}








