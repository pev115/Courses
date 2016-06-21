/* this file contains the computation function for driver.cpp */

#include<iostream>
#include"prime_tester.h"
#include<cmath>

using namespace std;

bool is_it_prime(int number){

	if(
	(number<0
	|| number==1 
	||(number % 2) == 0
	||(number % 3) == 0
	||(number % 5) == 0
	||(number % 7) == 0
	||(number % 11) == 0
	||(number % 13) == 0
	||(number % 17) == 0
	||(number % 19) == 0
	||(number % 23) == 0
	||(number % 29) == 0
	||(number % 31) == 0
	)
	&&
	(
	number !=2
	&&number !=3
	&&number !=5
	&&number !=7
	&&number !=11
	&&number !=13
	&&number !=17
	&&number !=19
	&&number !=23
	&&number !=29
	&&number !=31
	))
	{
	return false;
	}
	else
	{
	return  true;
	}

}
