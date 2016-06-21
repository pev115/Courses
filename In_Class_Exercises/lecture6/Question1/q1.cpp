/*this program tests arrays */

#include <iostream>
#include "IntegerArray.h"
#include<cmath>

using namespace std;

int main(){
  cout<<endl<<endl<<"Let us now input 5 elements into an array -->a1<-- "<<endl<<endl;
  int nb=10;
  int testarray[nb];
  int testarray2[nb];
  double stdeviation;
  
  input_array(testarray, 5);
  
  cout<<endl<<"The array a1 : "<<endl;
  display_array(testarray, 5);

  cout<<"Now lets copy the elements of the array a1 to the array a2.";
  cout<<endl<<endl;
  
  copy_array(testarray, testarray2, 5);
  
  cout<<endl<<endl <<"Now lets display array 2" <<endl;

  display_array(testarray2, 5);

  cout<<"Its  the same!!!!"<<endl<<endl;
  
  cout<< "Now the stdev   :  "<<endl;

  stdeviation= stdev(testarray, 5);
  
  cout<<"The standard deviation of the array is : "<<stdeviation<<endl<<endl;
  

  return 0;



}
