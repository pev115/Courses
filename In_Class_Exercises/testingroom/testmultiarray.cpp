#include <iostream>
#include <iomanip>

using namespace std;

void populateArray(char*** & point_arr){

  point_arr = new char**[10] ; //create the 10 rows
  
  //cout<<"the adress of point arr is : " << *point_arr;

  //populate the rows
  for (int i=0; i<10;i++){
    point_arr[i]= new char*[10];
    for(int j=0 ; j<10; j++){
      point_arr[i][j] = new char[3];
      point_arr[i][j][0] = j+65;
      point_arr[i][j][1] = i+48;
      point_arr[i][j][2] = '\0';
    }
  }  
}


void populateArray( char norm_array[][10][3]){
  for(int i =0; i<10;i++){
    for(int j=0 ; j<10;j++){
      norm_array[i][j][0]=j+65;
      norm_array[i][j][1]=i+48;
      norm_array[i][j][2]='\0';
    }
  }
}


void printArray(char norm_array[][10][3]){
  cout<<"printing norm array"<<endl;

  for(int i =0; i<10;i++){
    for(int j=0 ; j<10;j++){
      cout<<setw(3);
      for (int k=0 ; k<2;k++){
	cout<<norm_array[i][j][k];
      }
    }
    cout<<endl;
  }
  cout<<endl;
} 



void printArray(char *** array){
  cout<<"entering printArray";
  cout<<endl;
  for(int i=0 ; i<10 ; i++){
    for(int j=0; j<10;j++){
      cout<<setw(3);
      for(int k=0;k<2;k++){
	cout<<array[i][j][k];
      }
      
    }
    cout<<endl;
  }
  cout<<endl;
  
}

void swap(int* list, int i , int j){
  int temp;
  temp = list[i];
  list[i] = list[j];
  list[j]=temp;

}

int minimum_of(int i , int j){
  
  if(i<j)
    return i;
  
  return j;

}

void selectionSort(int* list){

  for(int i=0; i<17; i++){
    for(int j=i; j<17;j++){
      
      if(minimum_of(list[i],list[j])== list[i])
	continue;
      
      swap(list, i,j);
  }

}
}


void printArray(int* list){
  for(int i=0; i<17; i++){
    cout<< list[i];

  }
  cout<<endl;


}




void quickSort(int* list,int min_index, int length){
  if(min_index>=(length-1))
    return;

  int piv_index = (min_index+(length-1)) /2;
  
  int left_arrow=min_index;
  int right_arrow=length-1;
  
  
  while(left_arrow<right_arrow){
    while(list[left_arrow]<list[piv_index]){
  
      left_arrow++;
    }
      
    while(list[right_arrow]>list[piv_index]){
      

  
      right_arrow--;
    }
    

   
    swap(list, left_arrow, right_arrow);
    left_arrow++;
    right_arrow--;
    //    printArray(list);
    //cout<<endl;
  }
  
  quickSort(list,0,piv_index-1);
  quickSort(list,piv_index, length);


}



int main(){

  //a)
  char *** dyn_arr =NULL;

  char norm_array[10][10][3];

  populateArray(dyn_arr);
  populateArray(norm_array);
  // cout<<"all good so far"<<endl;
   printArray(dyn_arr);
   printArray(norm_array);
   
   int list[17] = {1,2,3,3,2,5,6,6,3,3,45,3,1,2,4,8,99};
   int list2[17];

   for(int i=0; i<17;i++){
     list2[i]=list[i];
   }
   
   
   //Now do a selection sort
   selectionSort(list);
   
   printArray(list);
   
   quickSort(list2,0,17);
   printArray(list2);

  return 0;
}