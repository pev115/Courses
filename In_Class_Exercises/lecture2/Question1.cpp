/*This program will create a table for conversion of temperatures */
#include<iostream>
#include<iomanip>
using namespace std;

int min_temp; 
int step;
int max_temp;

int main(){


	//prompt the user to input the needed parameters
	cout<<" This program allows you to create a table of conversion between the most popular "
	<< "temperature scales. If you are ready to start enter the minimum fahrenheit temperature "
	<<"you would like the table to display and press enter."<<endl;
	cin>> min_temp;
	cout<<"Great, now input the maximum temperature you would like to be displayed then press "
	<<"space and finally enter the step size of your table. Once you are done press enter to generate "
	<<"table.";
	cin>> max_temp>>step;

	//output the table description and the headers
	cout<< endl<<endl<<endl;
	cout<< "The following is your requested table for converting farenheit to celcious and Kelvin "
	<<"from a minimum temperature of "<< min_temp<<"F to a maximum temperature of "<<max_temp<<"F in steps of "
	<< step<< "F" <<endl;
	cout<<setw(20)<<"F"<<setw(20)<<"C"<<setw(20)<<"K"<<endl<<endl;
    	
	//set the decimal places of the output to 2
	cout.setf(ios::fixed);
	cout.precision(2);
	
	//create the table
	for (double F=min_temp ; F <= max_temp ; F+= step){
	double C = (F-32)*static_cast<double>(5)/9 ;
	double K = C +273.15;
	
	cout<< setw(20) << F << setw(20)<< C << setw(20)<< K<< endl;
	}
	//Create the title
	cout<< setw(50) <<"Temperature Conversion Table"<<endl;
	cout<<setw(50)<<"----------------------------"<<endl;



       return 0;

}
