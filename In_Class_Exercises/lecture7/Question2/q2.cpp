#include<iostream>
#include<cstring>

using namespace std;

enum logic{False, True};

logic order(char string1[], char string2[]);
void print(logic testresult, logic testresult2);
logic  orderp(char* string1, char* string2);

int main(){
  int max =100;
  char string1[max];
  char string2[max];

 start:
 
  cout<<"Input the first string of characters "<<endl;
  cin>>string1;

  cout <<"input the second string of characters "<<endl;
  cin>>string2;
  
  if( !strcmp(string1, string2)){ 
    cout<<"The two strings are alphabetically the same, start again "<<endl;
    goto start;
  }



  logic testresult = order(string1, string2);
  logic testresult2 = orderp(string1, string2);

  print(testresult, testresult2);

  return 0;

}
 //Non pointer-arithmetic way:

logic  order(char string1[], char string2[])  {
  int count;
  int size1 = strlen(string1);
  int size2 =strlen(string2);
  
  if( size1> size2){
    count = size2;
  }else{count = size1;}
  

  for(int i=0;i<count;i++){
    if(string1[i]!= string2[i]){
      return ( *(string1+i) <*(string2+i)) ?  True :  False ; }
    
  }
  return (size1<size2)? True: False; 
}



//pointer arithmetic way:

logic  orderp(char* string1, char* string2)  {
  int count;
  int size1 = strlen(string1);
  int size2 =strlen(string2);
  
  if( size1> size2){
    count = size2;
  }else{count = size1;}
  

  for(int i=0;i<count;i++){
    if(*(string1+i)!= *(string2+i)){
      return ( *(string1+i) <*(string2+i)) ?  True :  False ; }
    
  }
  return (size1<size2)? True: False; 
}



void print(logic testresult,logic testresult2){
    
    switch(testresult){
    case True : cout<<endl<< "String 1 is alphabetically SMALLER  than string 2"<< endl; break;
    case False : cout<<endl<< "String 1 is alphabetically BIGGER  than string 2"<< endl; break;
    } 
 switch(testresult2){
    case True : cout<<endl<< "Pointer arithetic:String 1 is alphabetically SMALLER  than string 2"<< endl; break;
    case False : cout<<endl<< "Pointer arithetic:String 1 is alphabetically BIGGER  than string 2"<< endl; break;
    } 
  }





