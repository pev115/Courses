/*This file counts and prints all the characters in its own source code */

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


int counting_function();
void printing_function(int count);

int main(){
  
  int count = counting_function();
  
  printing_function(count);

  
  return  0;
}




int counting_function(){


  int count;
  char car;
  ifstream instream;
  instream.open("q4.cpp");

  if(instream.fail()){

    cout<<endl<<endl<< "FAIIIILLLLLLLLL !!!!! Bye bye"<<endl<<endl;
    exit(1);

  }
  instream.get(car);
  count=0;

  while(!instream.eof()){
    count++;
    
    instream.get(car);
  }
  instream.close();
  return count;
  
}

void printing_function(int count ){
  char car;

  for(int k=count; k>0 ; k--){

      ifstream instream;
      instream.open("q4.cpp");
      if(instream.fail()){
	cout<<endl<<endl<< "FAIIIILLLLLLLLL !!!!! Bye bye"<<endl<<endl;
	exit(1);
      }

      for(int i=1; i<=k; i++){
    
	instream.get(car);
      }

    cout<<car;

    instream.close();

  }



}
