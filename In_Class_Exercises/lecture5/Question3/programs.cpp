#include <iostream>
using namespace std;

void programa();
void programb();
						
int main()
{
int number;
cout<<"input a number :";
cin>> number;

if(number==0){
programa();
}else{
programb();
}

//cout<< "test";
//int count =1;
//int count =2;
//cout<<endl<<count;
return 0;
}



void programa(){
int count = 1;
for (; count <= 5 ; count++)
{
int count = 1;
cout << count << "\n";
}
	

}



void programb(){

int count = 1;
while (count <= 5)
{
int count = 1;
cout << count << "\n";
count++;
}


}	
