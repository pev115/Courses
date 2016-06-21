#include <iostream>
#include<fstream>
#include <cstdlib>
#include"errors.h"
#include "staticEncryptor.h"

using namespace std; 

 StaticEncryptor:: StaticEncryptor(const char* config_file ){
   //two temporary variables to hold the mapping pairs.
   int letter1;
   int letter2;
  
   ifstream in_stream;
   in_stream.open(config_file);
   if(in_stream.fail()){
     cout<<"Reflector configuration  File could not be opened!!"<<endl;
     exit(ERROR_OPENING_CONFIGURATION_FILE);
   }

   //Populate the map_array with the pairs in the configuratioin file
   in_stream>>letter1;
   in_stream>>letter2;

   while(!in_stream.eof()){
     map_array[letter1]=static_cast<char>(letter2+65);
     map_array[letter2]=static_cast<char>(letter1+65);
     in_stream>>letter1;
     in_stream>>letter2;
   }
  
   //For the unpaired letters, map them to themselves
   for(int i= 0 ; i<26; i++){
     if(static_cast<int>(map_array[i])<65 || static_cast<int>(map_array[i])>90){
       map_array[i]=static_cast<char>(i+65);
      
     }

   }
 
 }


char StaticEncryptor::encrypt(char input){

  int digit_input = input-65;
  
  return map_array[digit_input];


}

void StaticEncryptor::printArray(){
  cout<<endl;
  for(int i=0; i<26; i++){
    cout<<i<<" , " << map_array[i]<<endl;
      }
  cout<<endl;
}

