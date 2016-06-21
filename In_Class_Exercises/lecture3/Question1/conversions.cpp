#include "conversions.h"
#include<iostream>


/*FUNCTION TO CONVERT FARENHEIT TO CELCIUS */
double celcius_of(int fahr){
	return (static_cast<double>(5)/9)*(fahr-32);
}
/*END OF FUNCTION*/

/*FUNCTION TO CONVERT FAHTENHEIT TO ABSOLUTE VALUE*/
double absolute_value_of(int fahr){
	return((static_cast<double>(5)/9)*(fahr-32))+273.15;
}
/* END OF FUNCTION */

