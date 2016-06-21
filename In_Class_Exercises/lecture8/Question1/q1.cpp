/*This program computes the fibonnaci sequence */

#include<iostream>
#include<cstdlib>

using namespace std;
int fibonacci( int n);

int main() {

  int n;
  
  cout << "Input the index of the sequence you want to know the value of: ";
  cin>> n;
  
  cout<< "The value is : " << fibonacci(n)<<endl<<endl;





}

int fibonacci(int n){
  if (n<=0){
    cout<<endl<<"AAAARGGGGGHHH!           ...___... ...___... ...___..."<<endl<<endl;
    exit(1);
  }else if(n==1||n==2){
    return 1;
  }else{
    return (fibonacci(n-1) + fibonacci(n-2));
  }

    
}
  
