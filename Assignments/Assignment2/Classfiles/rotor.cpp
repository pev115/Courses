#include <iostream>
#include<fstream>
#include <cstdlib>
#include "staticEncryptor.h"
#include "enigma.h"
#include "../errors.h"
#include "rotor.h"

using namespace std;


Rotor::Rotor(int _position, const char* config_file): position(_position)
{
  rightmost_rotor = false;
  notch_flag = false;
  
  //read the config. file and populate the map_array and notch_array.
  int letter;
  int notch;
  
  ifstream in_stream;
  in_stream.open(config_file);
  if(in_stream.fail()){
     cout<<"Rotor configuration  File could not be opened!!"<<endl;
     exit(ERROR_OPENING_CONFIGURATION_FILE);
   }
  
  for(int i=0; i<26; i++){
    in_stream>>letter;
    map_array[i]=letter;
  }
  
  in_stream>>notch;
  int count = 0;
  while(!in_stream.eof()){
    notch_array[count]= static_cast<char>(notch+65);
    in_stream>>notch;
    count++;
  }
  
  //To mark the end of the notch_array put a Sentinel character.
  notch_array[count]='\0';
  
  in_stream.close();
}


bool Rotor::getNotchFlag(){
  return notch_flag;
}

void Rotor::setNotchFlag(bool flag_value){
  notch_flag= flag_value;
}

void Rotor:: setRightmostRotor(bool flag_value){
  rightmost_rotor = flag_value;

}

void Rotor::rotate(){
  this->position ++;
}



char Rotor::encrypt(char input){
  if(rightmost_rotor){
    rotate();
  }
  
  setNotchFlag(false);
  
  //shift input to take account of rotor position
  int digit_input = input-65;
  int rotated_input = ((digit_input+position) % 26);
  
  //if the notch is hit, turn the flag to true.
  for(int i=0; notch_array[i]!='\0'; i++){
    if (static_cast<char>(position+65)==notch_array[i]){
      notch_flag=true;
      break;
     }
  }
  //cout<<"  notch " << notch_array;
  
  //switch back to the absolute frame of reference.
  return static_cast<char>(((((map_array[rotated_input]-position) % 26)+26)%26)+65);
}




 char Rotor:: reverseEncrypt(char input){
   
   //cout<<endl<<" decr_abs_input : " << input <<" ";

   int digit_input = input-65;
   
   //cout<<endl<<" decr_digit_input : " << digit_input <<" ";
   
   //shift input to account for rotor position.
   int rotated_input = ((digit_input+position) % 26);

   //cout<<endl<<" decr_rot__input : " << rotated_input <<" ";
    
   int digit_output = indexOf(rotated_input);

   // cout<<endl<<" decr_digit_output : " << digit_output <<" ";
   
   //switch back to absolute frame of reference.
   return static_cast<char>(((((digit_output-position) % 26)+26)%26)+65);

 }





int Rotor::indexOf(int value){

  // printArray();

  for (int i=0 ; i<26;i++){
    if(map_array[i]==value){
      return i;
    }
  }
  cout<<"Fatal Error: Something went Wrong @ rotor.cpp: Rotor::indexOf ";
  exit(UNIDENTIFIED_ERROR);
}







void Rotor::printArray(){
  cout<<endl;  
for (int i = 0 ; i<26 ; i++){
    cout<<i<<" , "<<map_array[i]<<endl;
  }
}


int Rotor::getPosition(){

  return position ;
}





