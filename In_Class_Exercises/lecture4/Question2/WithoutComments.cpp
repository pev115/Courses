

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

void flagswitch(char car, char nextcar, int& flag);



int main(){
  
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n"; 
  
  int  flag=0;
  char car;
  char nextcar;
  
  
  ifstream instream;
  ofstream outstream;
  
  
  instream.open("q2.cpp"); if(instream.fail()){ cout<<"ARGHHH!!!(in)"; exit(1);}
  outstream.open("WithoutComments.cpp");if(outstream.fail()){ cout<<"ARGHHH!!!(out)"; exit(1);}
  
  instream.get(car);
  
  
  while(!instream.fail()){
    instream.get(nextcar);
    instream.putback(nextcar);

    
    flagswitch(car, nextcar, flag);
    
    
    if(flag==0){outstream.put(car);}
    instream.get(car); 
    
    

  }
  instream.close();
  outstream.close();
  return 0;
  
  
 
}


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


 





 




}
