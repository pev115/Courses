#include <iostream>
#include<fstream>
#include <cstdlib>
#include "staticEncryptor.h"
#include "enigma.h"
#include "errors.h"
#include "rotor.h"

using namespace std;





//////////////////////////////////////MAIN///////////////////////////////////////////

int main (int argc, char** argv){

  //Instantiate the enigma
   Enigma enigma(argc, argv);
  
   enigma.outputMessage();

  // Rotor rotor(1, argv[1]);
  
  // for (int i = 65; i<91 ; i++){
  // cout<<endl<< rotor.encrypt(i)<<endl;}
  // StaticEncryptor testplc(argv[1]);
  //StaticEncryptor testref(argv[2]);

 
  //cout<<endl<< " TEEEESSSTTTTTT pluckboard: " <<testplc.encrypt('A')<<endl; 
  // cout<<endl<< "the arrray is ";
  // testplc.printArray();
  // cout<<endl<< " TEEEESSSTTTTTT ref: " <<test.encrypt('')<<endl; 
  //test.printArray();
  
}
//////////////////////////////////////////////////////////////////////////////////////


