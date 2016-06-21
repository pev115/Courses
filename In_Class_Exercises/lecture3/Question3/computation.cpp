/* 
Author: Eugene Valassakis
Created Date: 9 oct 2015


This program computes the averages of one, two three and four rational numbers.
*/

#include <iostream>
#include "statistics.h"
using namespace std;
void print1();
void print2();
void print3();
void print4();
void elseprint();
void print0();


double value1;
double value2;
double value3;
double value4;



/*Start of main part of the program */
int main(){

cout<<endl<<endl<<endl<<"This program tests the functions in the 'statistics.h' header file."<<endl<<endl;

int number =1;
	while (number !=0){
		cout<<"Do you whish to test 1,2,3 or 4 numbers (enter 0 to end the program): ";
		cin>> number;

		if (number ==1){
			print1();	
		}else if(number ==2){
			print2();
		}else if(number ==3){
			print3();
		}else if(number ==4){
			print4();
		}else if(number != 0){
			elseprint();
		}
		
	}

print0();
return 0;

}
/*End of main part of the program*/


/*Print 1 to print 4 will print the appropriate messages and compute
the appropriate statistics depending on the computation number entered by the user.*/

void print1(){

cout<<"Enter First Value: ";
cin>>value1;
cout<<"Average: "<< value1 <<" Standard deviation: "<< 0 <<endl<<endl;

}


void print2(){

cout<<"Enter First Value ";
cin>> value1;
cout<<"Enter Second Value ";
cin>>value2;
double average_value = average(value1,value2);
cout<<"Average: "<< average_value <<" Standard deviation: "<< stdev(value1,value2,average_value)
<<endl<<endl;

}


void print3(){

cout<<"Enter First Value ";
cin>> value1;
cout<<"Enter Second Value ";
cin>>value2;
cout<<"Enter Third Value ";
cin>>value3;
double average_value = average(value1,value2,value3);
cout<<"Average: "<< average_value <<" Standard deviation: "<< stdev(value1,value2,value3,average_value)
<<endl<<endl;

}



void print4(){

cout<<"Enter First Value ";
cin>> value1;
cout<<"Enter Second Value ";
cin>>value2;
cout<<"Enter Third Value ";
cin>>value3;
cout<<"Enter Fourth Value ";
cin>>value4;
double average_value = average(value1,value2,value3, value4);
cout<<"Average: "<< average_value <<" Standard deviation: "<< stdev(value1,value2,value3,value4, average_value)
<<endl<<endl;

}

void elseprint(){

cout<<"Sorry, the program can only test for 1,2,3 or 4 values!!!! "<<endl<<endl;

}

void print0(){

cout<<"Finished testing the 'statistics.h' file"<<endl<<endl;

}
/*End of the printing functions*/

