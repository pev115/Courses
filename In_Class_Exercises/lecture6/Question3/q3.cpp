/*This program inputs a string and outputs it without any character repetitions */

#include<iostream>
#include<cstring>

using namespace std;

void  no_repetitions(char phrase[],char  nospace[], int length);
bool character_exists(char input[],char nospace[],int count, int nospacecount);

int main(){

  int max =101;
  char phrase[max];
  char nospace[max];
  cout<<endl<<endl<< "Type a string max 100 char : ";
  cin.getline(phrase,max);
  no_repetitions( phrase,nospace,max);

  cout<<endl<<endl<<"The string without any repetitions is : "<<nospace<<endl<<endl;
  return 0;
}

void  no_repetitions(char phrase[],char  nospace[], int length){
  nospace[0]=phrase[0];
  int count =1;
  int nospacecount=1;
  while( count !='0'){
    if(!character_exists(phrase,nospace,count, nospacecount)){
      nospace[nospacecount]=phrase[count];
      nospacecount++;
      }
    count++;
  }
  
  nospace[nospacecount+1]='\0';

}

bool character_exists(char input[],char nospace[],int count, int nospacecount){
    for(int i=0;i<nospacecount;i++){
      if(input[count]==nospace[i]){return true;}
    }

    return false;

  }
