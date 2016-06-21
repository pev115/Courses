/* This program storts strings */


#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

void str_sort(char a[],int length);
int minimum_from(char a[], int position, int length);
void swap(int& first, int& second);

int main(){

  int length=101;
  char phrase[length];
  

  cout<<endl<<endl<<"Type in a string of max 100 characters: ";
  cin.getline(phrase,101); 
  str_sort(phrase,length);
  cout<<endl<<endl<<"The Sorted phrase is :" << phrase <<endl<<endl;
  return 0;

}


void str_sort(char a[],int length){

  for (int count = 0 ;  a[count]!='\0' ; count++)
  swap(a[count],a[minimum_from(a,count,length)]);
	
	

}



int minimum_from(char a[], int position, int length)
{
  int min_index = position;
  
  for (int count = position + 1 ; a[count]!='\0' ; count ++)
    if (static_cast<double>(a[count]) < static_cast<double>(a[min_index]))
      min_index = count;
	
  return min_index;
}
	
void swap(char& first, char& second)
{
  char temp = first;
  first = second;
  second = temp;
}