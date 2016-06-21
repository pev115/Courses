/* 
Created by : Eugene Valassakis 
Last modified : 07/10/2015

This is a program that will raise a number x to a power n. Both numbers will
be input by the user*/

#include <iostream>
#include <cmath>


using namespace std;

int main(){

double x;
double power = 1;
int n;
//Get the user input
cout<<endl<<endl<<endl<<"This program will calculate how to raise a number x to a positive integer power n."<<endl<<endl;
cout<<"Insert x:";
cin >> x ;
cout<<"now insert n:";
cin>>n;
cout<<endl;

//First we will make a for loop to create the powering. Three cases : n<0, n=0 , n>0
if(n<0){
	cout<<"I told you a positive integer !!! The minimum you can input is 0"<<endl<<endl;
	return 0;
}else if(n==0){
	cout<< x<< " to the power " << n << " is " << x <<endl<< endl;
	return 0;
}else{
	for(int i =1; i<=n; i++){
	power = power*x;
	}
}

cout<< "first compute doing the for loop"<<endl; 
cout<< x <<" to the power "<< n <<" is " << power<< endl<<endl ;

//Now compute with the cmath library

 power = pow(x,n);
cout<<" Now compute using the cmath library"<< endl;
cout<< x <<" to the power "<< n <<" is " << power<< endl ;
cout<<"This is much faster!!!!!"<< endl<<endl;

return 0;


}


