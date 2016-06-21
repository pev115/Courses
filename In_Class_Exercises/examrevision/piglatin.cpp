#include "piglatin.h"

#include <cstring>
#include <cctype>
using namespace std;
int findFirstVowel(const char* word){
  int length= strlen(word);
  for(int i=0; *(word+i)!='\0';i++){
    if(isVowel(*(word+i), i, length)){
      return i;
    }
  }
  return -1;
}

bool isVowel(char ch, int position, int length){
  switch (ch){
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  case 'y':
    if(position == length-1 || position == 0)
      return false;
    return true;
  default:
    return false;

  }
}

void translateWord(const char* eng, char* piglat){
  
  if(findFirstVowel(eng)==0){
    strcpy(piglat,eng);
    strcat(piglat,"way");
  }else if(findFirstVowel(eng) ==-1 && !isdigit(*eng)){
    strcpy(piglat,eng);
    strcat(piglat,"ay");
  }else if(isdigit(*eng)){
    strcpy(piglat,eng);
  }else{
    bool upperflag=false;
    if(isupper(*eng)){
      upperflag=true;
    }

    int pos= findFirstVowel(eng);
    char temp[strlen(eng)+6];
  
    
    for(int i=0; i<pos;i++)
      temp[i]= *(eng+i);
    temp[pos] ='\0';
   
  if(upperflag){
      *temp = tolower(*temp);
    }

    for(unsigned int i=pos; i<strlen(eng);i++){
      piglat[i-pos]=eng[i];
    }
    piglat[strlen(eng)-pos] ='\0';
    
    strcat(piglat,temp);
    strcat(piglat,"ay");

    if(upperflag==true)
      *piglat= toupper(*piglat);

  }

}


void translateStream(ifstream& in_stream ,ostream& out_stream){
  if(in_stream.eof())
    return;

  
  char txt[100];
  char piglat [100];
  int count=0;
  
  in_stream.get(*txt);

  while(isalpha(*(txt+count)) ||isdigit(*(txt+count))){
    if(in_stream.eof())
      return;

    count++;
    in_stream.get(*(txt+count));
  }


  in_stream.putback(*(txt+count));
   *(txt+count) ='\0';

  if(!isalpha(*txt) && !isdigit(*txt)){
    strcpy(piglat,txt);
  }else{
    translateWord(txt,piglat);
  }

  out_stream<<piglat;

  /*
  if(*(txt+count) =='\n')
    out_stream <<'\n';
  
  out_stream<< ' ';
  */
  translateStream(in_stream, out_stream);

}
