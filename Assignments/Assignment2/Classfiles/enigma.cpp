#include <iostream>
#include<fstream>
#include <cstdlib>
#include "staticEncryptor.h"
#include "enigma.h"
#include"rotor.h"

using namespace std;


Enigma::Enigma( int par_nb, char** config_files) {

  //Set the user input message.
  setInputMessage(); 
  //cout<< "The input message is " << input_message ; 


  //Set the pluckboard.
  //setPluckbrd(config_files[1]);    //<-----WHYYYYYYYYYYYYY
  StaticEncryptor pluckboard(config_files[1]);
  this-> pluckbrd = &pluckboard;
  //cout<<endl<<"The pluckboard array created is : " ;
  // pluckbrd->printArray();


  //Set the reflector.
  //setReflector(config_files[2]);     //<-----WHYYYYYYYYYY
  StaticEncryptor reflector(config_files[2]);
  this->reflec = &reflector;
  // cout<<endl<<"The reflector array created is : " ;
  //reflec->printArray();


  //Set the number of rotors 
  number_of_rotors = par_nb-4;
  //cout<<endl<<"number of rotors : " << number_of_rotors;

  //Only attempt to create rotors if there are any.
  if(number_of_rotors>0){
    
    //Put the rotor configuration files in a separate array.
    char** rotor_config_files;
    rotor_config_files = new (nothrow) char*[par_nb-3];
    for (int i= 0 ; i<(par_nb-3); i++){
      rotor_config_files[i] = config_files[i+3];
    }
    /*cout<<endl<<" The rotor file list is :" <<endl;
      for (int i= 0; i<par_nb-3; i++){
      cout<<rotor_config_files[i]<<endl;
      } 
    */


 
    //Create the rotor pointer array dynamically with
    // each element pointing to one of the rotors.
    rotor_array = new (nothrow) Rotor*[number_of_rotors];
    // setRotors( rotor_config_files);

    //Open a file stream to fetch the initial position of the rotors.
    ifstream in_stream;
    in_stream.open(rotor_config_files[number_of_rotors]);
    if(in_stream.fail()){
      cout<<"Rotor initial position  File could not be opened!!"<<endl;
      exit(ERROR_OPENING_CONFIGURATION_FILE);
    }
     

    //Dynamically allocate a rotor to each of the array elements.
    int initial_position;
    for(int i=0; i<number_of_rotors;i++){
      in_stream>>initial_position;
      //setRotor(i,initial_position,rotor_config_files[i]);
      // Rotor rotor(initial_position, rotor_config_files[i]);

      // cout<<endl<<"the config file for rotor "<< i <<" is " << rotor_config_files[i];
      // cout<<endl<<"its position is " << initial_position;
      // cout<<endl<<"its array is ";    rotor.printArray();

      //this->rotor_array[i] = &rotor;
    
      rotor_array[i]= new Rotor(initial_position, rotor_config_files[i]);
    }
 
    //PRINT THE ARRAYS OF THE ROTOR_ARRAY
    /* cout<<endl<< "PRINT THE ARRAYS OF THE ROTOR_ARRAY ";
       for (int i=0; i<number_of_rotors;i++){
       cout<< endl<< "rotor_array with index  " <<i;
       rotor_array[i]->printArray();
       }
    */


    in_stream.close();
    //Set the rightmost rotor.
    rotor_array[number_of_rotors-1]->setRightmostRotor(true);

  }
}

void Enigma:: setInputMessage(){

  //Read the input message from the screan (or redirected file)
  int i= 0 ;
  char character;
  cin>>ws;
  cin>>character;
  
  while (!cin.eof()){
    
    input_message[i]=character;
    cin>>ws;
    cin>>character;
    i++;
  }
  //Mark the end of the message with the sentinel character.
  input_message[i]='\0';
 
}


void Enigma::outputMessage(){
  //Create a string for the output message
  char outputMessage[MAXLENGTH];
  //cout<< "The output message is ";
  int i =0;
 
  while (input_message[i]!='\0'){
    //Encrypt each input character and output it.
    outputMessage[i]=this->encrypt(input_message[i]);
    cout<<outputMessage[i];
    i++;
  }
  cout<<endl;
}


char Enigma::encrypt(char input){
  //Variable to hold the encryption.
  char crypted_char;
  
  //Go through the pluckboard.
  crypted_char = pluckbrd->encrypt(input);
  // cout<<endl<<"crypted char after pluckboard "<< crypted_char;
  
  //Go through the rotors.
  for( int i =number_of_rotors-1 ; i >=0; i--){

    // cout<<endl<<"BEFORE  rotor "<< i << " (counting from the left) ";
    // cout<<crypted_char;
    // rotor_array[i]->printArray();

    crypted_char = rotor_array[i]->encrypt(crypted_char);

    //cout<<endl<<"After rotor "<< i << " (counting from the left) ";
    //cout<<crypted_char;
    //cout<<endl<<" the notch of rotor " <<i << " is " << rotor_array[i]->getNotchFlag();
    
    //Rotate the next rotor if notch is hit.
    if(i != 0 && rotor_array[i]->getNotchFlag()){
      rotor_array[i-1]->rotate();
    }
    
    //if(i!=0)
      // cout<<endl<<"the position of rotor " << i-1 << " is "<< rotor_array[i-1]->getPosition();
  }
  
  // cout<<endl<<"crypted char after encrypt rotors "<< crypted_char;
  
  //Go through the reflector.
  crypted_char=reflec->encrypt(crypted_char);
  //cout<<endl<<"crypted char after reflector "<< crypted_char;

  //Go through the rotors in the opposite direction.
  for (int i = 0 ; i< number_of_rotors; i++){
    crypted_char = rotor_array[i]->reverseEncrypt(crypted_char);
  }
  
  // cout<<endl<<"crypted char after deccrypt rotors "<< crypted_char;

  //Go through the pluckboard.
  crypted_char = pluckbrd->encrypt(crypted_char);
 
  // cout<<endl<< "crypted char after second pluckboard " <<crypted_char<<endl;

  return crypted_char; 
}













/*


void Enigma::setPluckbrd( const char* pluckbrd_config){
  // cout<<endl<<"The pluckboard config file : " << pluckbrd_config;
  //Instatiate the pluckboard and assign it to the member variable
  StaticEncryptor pluckboard(pluckbrd_config);
 this-> pluckbrd = &pluckboard;

}


void Enigma:: setReflector( const char* reflect_config){
  
 //Istantiate reflector and assign it to the member variable
  StaticEncryptor reflector(reflect_config);
  this->reflec = &reflector;

}





void Enigma::setRotors( char** rotor_config_files){ // NEED SET THE FIRST ROTORX
 
  ifstream in_stream;
  in_stream.open(rotor_config_files[number_of_rotors]);
  if(in_stream.fail()){
    cout<<"Rotor initial position  File could not be opened!!"<<endl;
    exit(ERROR_OPENING_CONFIGURATION_FILE);
  }
      
  int initial_position;
  for(int i=0; i<number_of_rotors;i++){
    in_stream>>initial_position;
    setRotor(i,initial_position,rotor_config_files[i]);
  }
 
  in_stream.close();

  rotor_array[number_of_rotors-1]->setRightmostRotor(true);
}



void Enigma::setRotor(int rotorNb, int position,const char * rotor_config){
   Rotor rotor(position, rotor_config);
   this->rotor_array[rotorNb] = &rotor;
 }

*/
