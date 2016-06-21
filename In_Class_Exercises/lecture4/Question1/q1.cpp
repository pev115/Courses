/* This is a program that outputs itself */

#include<iostream>
#include<fstream>

using namespace std;

int main(){
  
  cout<<endl<<endl<<"Follows a copy of this program : "<<endl<<endl; 

  ifstream in_stream;
  in_stream.open("q1.cpp");
  char car;
  
  in_stream.get(car);
  while(!in_stream.eof()){
    cout<<car;
    in_stream.get(car);

  }





}
