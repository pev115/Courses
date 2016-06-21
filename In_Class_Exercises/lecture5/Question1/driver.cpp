/*Author : Eugene Valassakis
 Created date: 11 OCT 2015

This Program returns true if the input integer between 1 and 1000 is a prime number */

#include<iostream>
#include"prime_tester.h"
using namespace std;

int main(){

int number;

cout<<endl<< "Input an integer from 1 to 1000 or 0 to terminate the program : ";
cin>>number;

	while (number !=0){
	bool test_prime = is_it_prime(number);
	
		if (number >1000){
		cout<< "This number is too big, can't handle it!!!"<<endl<<endl;
		}else{
			if (test_prime){
			cout<<endl<<number<<" is a prime number !! Congratulations!!!"<<endl<<endl;
			}else{
			cout<<endl<<number<<" is not a prime number. Sorry mate, you must try again :( ..";
			}
		}
	cout<<endl<< "Input an integer from 1 to 1000 or 0 to terminate the program : ";
	cin>>number;
	}
	
	cout<<endl<<"You just destroyed this program to dust!!! Bye now. "<<endl<<endl;
	return 0;
}
