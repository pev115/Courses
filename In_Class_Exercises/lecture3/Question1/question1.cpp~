/* This program prints out a conversion table of temperatures, after prompting the user
for upper and lower bounds of the table in fahrenheit, and the temperature difference between table  entries. 

 Created by : Eugene Valassakis
Created date : 07/10/2015 */

#include<iostream>
#include"conversions.h"
using namespace std;


void print_message_echoing_input(int lower, int upper, int step);
void input_table_specifications(int& lower,int& upper,int& step);
void print_preliminary_message();
void print_table(int lower,int upper,int step);

/*START OF MAIN PROGRAM */

int main(){

	int lower = 0 ; //the lowest farenheit entry in the table
	int upper =0 ; //the heighest farenheit entry in the table
	int step = 1; // difference in fahrenheit between entries

	/* print a message explaining what the program does: */
	print_preliminary_message();
	
	//prompt the user for table specifications in farenheit:
	input_table_specifications(lower, upper, step);
	
	//print appropriate message including an echo of the input:
	print_message_echoing_input(lower, upper, step);
	
	//Print the table (including the column headings):
	print_table(lower, upper, step);

	return 0;

}

/*END OF MAIN PROGRAM */

/*FUNCTION to print a message explaining what the program does: */

void print_preliminary_message(){
cout<<"This program prints out a conversion table of temperatures."<<endl<<endl;
}
/* END OF FUNCTION */


/*FUNCTION to prompt the user for table specifications in farenheit: */

void input_table_specifications(int& lower,int& upper,int& step){
cout<<endl<<"If you are ready to start enter the minimum fahrenheit temperature "
<<"you would like the table to display and press enter."<<endl;

cin>>lower;

cout<<"Great, now input the maximum temperature you would like to be displayed then press "
<<"space and finally enter the step size of your table. Once you are done press enter to generate "
<<"table.";

cin>> upper>>step;

}

/* END OF FUNCTION */

/* FUNCTION to print appropriate message including an echo of the input: */
void print_message_echoing_input(int lower, int upper, int step){

cout<<endl<<endl<<"Temperature conversion table from " << lower << "F to " << upper
<<"F, in steps of "<< step<< "F"<<endl<<endl;

}
/*END OF FUNCTION*/

#include<iomanip>

/*FUNCTION to print the table (including the column headings):*/
void print_table(int lower,int upper,int step){

//set the decimal places of the output to 2
	cout.setf(ios::fixed);
	cout.precision(2);
	
	cout<< setw(20) << "F" << setw(20)<< "C" << setw(20)<< "K"<< endl;
	//create the table
	for (double F=lower ; F <= upper; F+= step){
	double C = celcius_of(F);
	double K = absolute_value_of(F);
	
	cout<< setw(20) << F << setw(20)<< C << setw(20)<< K<< endl;
	}
	//Create the title
	cout<<setw(50)<<"Temperature Conversion Table"<<endl;
	cout<<setw(50)<<"----------------------------"<<endl;

}
/*END OF FUNCTION*/








