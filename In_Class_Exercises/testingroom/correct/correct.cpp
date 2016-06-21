#include <iostream>
#include <cstring>
#include "correct.h"

using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1) 
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */

void text_to_binary(const char* str,char* binary){
  if(*str =='\0')
    return;


  char binary_char[9];

  ascii_to_binary(*str, binary_char);

  strcpy(binary,binary_char);

  text_to_binary(str+1,binary+8);

}


void binary_to_text(const char* binary, char* str){
  if(*binary =='\0')
    return;


  char binary_char[9];
  char letter[2];
  letter[1]='\0';
  strncpy(binary_char,binary,8);
  binary_char[9] ='\0';
  letter[0]=binary_to_ascii(binary_char);
  strcpy(str,letter );

  binary_to_text(binary+8,str+1);

}


char tochar(int digit){
  return '0'+digit;
}


void add_error_correction(const char* data, char* corrected){
  corrected[0]='\0';

  for(int i=0; *(data+i)!='\0'; i+=4){
    int j = i%4;
    const char* bit_pointer =data+i; 
    
    int d1= *(bit_pointer+j) - '0';
    int d2= *( bit_pointer+j+1) -'0';
    int d3= *(bit_pointer+j+2) - '0' ;
    int d4= *(bit_pointer+j+3) - '0';

    int c1 = parity(d1,d2,d4);
    int c2 = parity(d1,d3,d4);
    int c3 = parity(d2,d3,d4);
    
    char code[] ={tochar(c1),tochar(c2),
		  tochar(d1),tochar(c3),tochar(d2),
		  tochar(d3),tochar(d4),'\0'};
   
    strcat(corrected,code);
  }
}


int parity(int a, int b, int c){
  int sum = a+b+c;

  if (sum %2 == 0)
    return 0;
 
  return 1;

  }

int parity(int a, int b, int c, int d){
  int sum = a+b+c+d;

  if (sum %2 == 0)
    return 0;
 
  return 1;

}

void correct_bit(int pos, int& b1, int& b2, int& b3,
		 int& b4, int& b5, int& b6, int& b7){
  switch(pos){
  case 1: b1 == 0? b1=1 : b1 =0;
    break;
  case 2: b2 == 0? b2=1 : b2 =0;
    break;
  case 3: b3 == 0? b3=1 : b3 =0;
    break;
  case 4: b4 == 0? b4=1 : b4 =0;
    break;
  case 5: b5 == 0? b5=1 : b5 =0;
    break;
  case 6: b6 == 0? b6=1 : b6 =0;
    break;
  case 7: b7 == 0? b7=1 : b7 =0;
  }
}

int decode(const char* received, char* decoded){
  decoded[0]='\0';
  int count =0;
  for(int i=0; *(received+i)!='\0'; i+=7){
    int j = i%7;
    const char* bit_pointer =received+i; 
    
    int b1= *(bit_pointer+j) - '0';
    int b2= *( bit_pointer+j+1) -'0';
    int b3= *(bit_pointer+j+2) - '0' ;
    int b4= *(bit_pointer+j+3) - '0';
    int b5= *(bit_pointer+j+4) - '0';
    int b6= *(bit_pointer+j+5) - '0';
    int b7= *(bit_pointer+j+6) - '0';



    int p1 = parity(b4,b5,b6,b7);
    int p2 = parity(b2,b3,b6,b7);
    int p3 = parity(b1,b3,b5,b7);

    int error_check = p1 * 4 + p2*2 + p3;
    

    char decode_bits[5];
    decode_bits[4] ='\0';

    if(error_check ==0){
      decode_bits[0]= tochar(b3);
      decode_bits[1]= tochar(b5);
      decode_bits[2]= tochar(b6);
      decode_bits[3]= tochar(b7);
      strcat(decoded,decode_bits);
    }else{
      correct_bit(error_check,b1,b2,b3,b4,b5,b6,b7);
   
      decode_bits[0]= tochar(b3);
      decode_bits[1]= tochar(b5);
      decode_bits[2]= tochar(b6);
      decode_bits[3]= tochar(b7);
      strcat(decoded,decode_bits);
      count++;
    }
  }

  return count;
}
