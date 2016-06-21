/* This program outputs the line 

cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n"; 

and then ignores all comments while rewriting the program 
to a different file named WithoutComments.cpp */

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

void flagswitch(char car, char nextcar, int& flag);

/*Start of the main part of the program */

int main(){
  /*output the test output */
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n"; 
  /*declare the main variables */
  int  flag=0;
  char car;
  char nextcar;
  
  /*instantiate the streams */
  ifstream instream;
  ofstream outstream;
  
  /*open and create the relevant files*/
  instream.open("q2.cpp"); if(instream.fail()){ cout<<"ARGHHH!!!(in)"; exit(1);}
  outstream.open("WithoutComments.cpp");if(outstream.fail()){ cout<<"ARGHHH!!!(out)"; exit(1);}
  
  instream.get(car);
  
  /*Do the reading and copying of the files */
  while(!instream.fail()){
    instream.get(nextcar);
    instream.putback(nextcar);

    /*assign a value to the flag*/
    flagswitch(car, nextcar, flag);
    
    /* outstream only if flag is false and move on */
    if(flag==0){outstream.put(car);}
    instream.get(car); 
    
    

  }
  instream.close();
  outstream.close();
  return 0;
  
 
 
}

/*Define the funciton that switches the flags*/
void flagswitch(char car, char nextcar, int& flag){

 
  if((car=='/' && nextcar=='*'&& flag==0)){
    flag=1;
  }else if(car=='*' && nextcar =='/' && flag==1){
    flag=2; 
    
  }else if(car=='/' && flag==2){
    flag=3;
    return;

  }else if(flag==3){
    flag=0;
  }


 





 /* if((car=='/' && nextcar=='*')||(car=='*' && nextcar=='/')){
      switch(flag){
      case true : flag=false;break;
      case false: flag=true;break;
      default : cout<<"AAAAAARGGHHHH FLAAAGGG!!!!";
             	exit(1);
      }
      
      ;
      
      }
      
  */




}
