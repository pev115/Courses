#ifndef STATICENCRYPTOR_H
#define STATICENCRYPTOR_H

const int MAXLENGTH = 100000;
const int ABCLENGTH = 26;

/////////////////////STATIC_ENCRYPTOR/////////////////////////////////////
/*This is the static encryptor class. It can be instantiated to become either 
 to either a reflector or a pluckboard depending on the configuration file input
 */
class StaticEncryptor{
  
private:
  //Index correspons to the letter to be mapped and value to the encryped
  //letter
  char map_array[ABCLENGTH]; 
  
public:
  
  //Constructor : reads the configuration file and populates the map array
  //if the configuration file has less than 13 pairs, remaining letters
  //are mapped to themselves
  StaticEncryptor(const char* ref_config);

  //Receives the character to be encrypted and returns the encrypted value 
  //using the map_array.
  char encrypt(char input);

  //Debugging helper funcrion that prints map_array.
  void printArray();

};

//////////////////////////////////////////////////////////////////////////


#endif
