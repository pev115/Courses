/* This is an implementation file fort functions concering arrays */

#include <iostream>
#include"IntegerArray.h"
#include<cmath>
using namespace std;


//This is a function that prompt the user to input the first n elements of an array.
void input_array(int a[], int n){

  cout<<"You will now input the first "<< n<<" elements of the array " <<endl;
  
  for(int i=0; i<=n-1;i++){
    cout<<"Enter the array element "<< i << " now :"<<endl<<endl;
    cin>>a[i];

  }


}


void display_array(int a[], int n){
  
  cout<< "The Array elements are : "<<endl<<endl;

  for (int i=0; i<=n-1 ;i++){
    cout<<"a["<<i<<"] = "<<a[i]<<endl;
    
  }
  
  cout<<endl<<"Tadaaaa!!!!"<<endl<<endl;


}



void copy_array( int a1[], int a2[], int n){
  for (int i=0; i<=n-1 ;i++){
    a2[i]=a1[i];
  }
  cout<<"Copying done!!!!";

}


double  stdev(int a[],int n){
  double var ;
  int total=0;
  for(int i=0; i<=n-1; i++){
    total += a[i];
  }
  double ave = static_cast<double>(total)/n;
  
  for(int i =0;i<=n-1; i++){
    var += pow(static_cast<double>(a[i]-ave),2);
  }
  return  sqrt(var);
}