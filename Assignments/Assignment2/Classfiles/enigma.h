#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include<fstream>
#include <cstdlib>
#include "staticEncryptor.h"
#include"rotor.h"


using namespace std;

//////////////////////////////////////ENIGMA////////////////////////////////////
/*This is the Enigma class.Brings together the pluckboard, reflector and rotors
  to create the encryption.
*/
class Enigma{

private:
  //User input message, enigma components and number of rotors.
  char input_message[MAXLENGTH];
  StaticEncryptor* reflec;
  StaticEncryptor* pluckbrd;
  int number_of_rotors;
  Rotor** rotor_array;
  
  

public:  

  /*HELPER FUNCTIONS FOR CONSTRUCTOR : DO NOT WORK --->>>> CHECK WHY
  // void setRotors(char ** rotor_config_files);
  // void setRotor(int rotorNb, int position, const char* rotor_config);
  // void setReflector( const char* reflect_config);
  //void setPluckbrd( const char* pluckbrd_config); */
  


  //User input stripped of white space and put to input_message
  void setInputMessage();

  //Constructor: prompts the user for input and populates
  //the input_message accordingly.Creates StaticEncryptor
  //and Rotor objects as needed.
  Enigma(int par_nb, char** config_files);
  
  //Receives a single character  and returns the corresponding
  //encrypted character.Helper to outputMessage
  char encrypt(char input);

  //Uses the input_message to output the encrypted(or decrypted)
  //message on the standard output stream 
  void outputMessage();
  

};

////////////////////////////////////////////////////////////////////////////////

#endif
