#ifndef ROTORS_H
#define ROTORS_H


#include <iostream>
#include<fstream>
#include <cstdlib>
#include "staticEncryptor.h"
#include "enigma.h"
#include "errors.h"

using namespace std;




///////////////////////////ROTORS///////////////////////////////////
/* This is the Rotor class. Rightmost rotor has special a special 
   functionality activated by the rightmost_rotor flag.In the 
   following, the absolute frame of reference is "A on top".
*/
class Rotor{

private:

  int position; /*holds the shift of the rotor relative
		   to the absolute frame of reference. */

  int map_array[ABCLENGTH];/*holds the mapping of the rotor 
			     in the absolute frame of reference */

  char notch_array[ABCLENGTH+1];
  bool rightmost_rotor;
  bool notch_flag;
  
public:
  //Constructor: notch_flag and rightmost_rotor set to false by default.
  //Sets the position and reads the config. file to populate the 
  //map_array and notch_array accordingly.
  Rotor(int _position, const char* config_file);
  
  
  //Getter and Setter functions for the notch_flag.
  bool getNotchFlag(); 
  void setNotchFlag(bool flag_value);
  
  //Setter function for the rightmost_rotor flag.
  void setRightmostRotor(bool flag_value);
  
  //Function that increments the position by 1.
  void rotate();

  //Function that takes a char input and returns the encrypted
  //char output, both in the absolute frame of reference.
  //To be used when the signal gets in from right to left( after the
  //pluckboard).
  char encrypt(char input);
  
  //Helper function for reverseEncrypt. Returns the map_array index
  //of the input value.
  int indexOf(int value);
  
  //Function that takes in a character and returns the encrypted 
  //character. Both in the absolute frame of referece. To be used
  // when the signal gets in from left to right (after the reflector).
  char reverseEncrypt(char input);
  
  //Debugging helper functions.
  void printArray();
  int getPosition();
 

};
//////////////////////////////////////////////////////////////////////


#endif
