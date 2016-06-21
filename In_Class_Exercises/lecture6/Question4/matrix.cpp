/*This program lets you multiply an m*n matrix with and m*r matrix */


#include<iostream>
#include<iomanip>

using namespace std;

const int M=2;
const int N=2;
const int R=2;

//Two functions that allow us to input the values for the elements of the matrices A and B
void inputvalues(int a[][N], int row, int column);
void inputvalues2(int b[][R], int row, int column);
//A function to output the matrices and theit multiplication result
void outputvalues(int c[][R],int a[][N], int b[][R],int M, int N, int R);
//The function that takes care of the multiplication
void multiplymatrices(int a[][M], int b[][R],int c[][R], int row, int column, int sumconst);

//Start of the main part of the program
int main(){

  cout<<endl<<endl<<"This programs lets you multiply a MxN matrix with an NxR matrix where:"<<endl;
  cout<<"M="<<M<<", N="<<N<<", R="<<R<<endl<<endl;
  
  int matrixA[M][N];
  int matrixB[N][R];
  int matrixC[M][R];
  
  inputvalues(matrixA,M,N);
  inputvalues2(matrixB,N,R);
  
  multiplymatrices(matrixA, matrixB,matrixC, M,R,N);

  outputvalues(matrixC, matrixA, matrixB,M,N,R);

  return 0;
  

}


void inputvalues(int a[][N], int row, int column){
  cout<<"Input the values for the FIRST "<<M<<"x"<<N<<"martrix"<<endl;
  
  for (int i=0; i< row; i++){
    cout<<"Type in "<<column<<" values sepated by space for row "<< i<<" : ";

    for (int j=0;j<column; j++){
      cin>>a[i][j];
	}
  }
  cout<<endl<<endl;
}
void inputvalues2(int b[][R], int row, int column){
  cout<<"Input the values for the SECOND "<<N<<"x"<<R<<"martrix"<<endl;
  
  for (int i=0; i< row; i++){
    cout<<"Type in "<<column<<" values sepated by space for row "<< i<<" : ";

    for (int j=0;j<column; j++){
      cin>>b[i][j];
	}
  }
  cout<<endl<<endl;
}



void outputvalues(int c[][R],int a[][N], int b[][R],int M, int N, int R){

  //cout.setf(ios::fixed);
  // cout.width(5);
  
  cout<<"The FIRST matrix is :"<<endl<<endl;
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cout<<setw(5)<<a[i][j];
    }
    cout<<endl;
  }

  cout<<endl;

  cout<<"We multiply it by the SECOND matrix which is :"<<endl<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<R;j++){
      cout<<setw(5)<<b[i][j];
    }
    cout<<endl;
  }

  cout<<endl;

  cout<<"This Gives the following result :"<<endl<<endl;
  
  for(int i=0;i<M;i++){
    for(int j=0;j<R;j++){
      cout<<setw(10)<<c[i][j];
    }
    cout<<endl;
  }

  cout<<endl<<endl;
}


void multiplymatrices(int a[][N], int b[][R],int c[][R], int row, int column, int sumconst){

  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      c[i][j]=0;
      for(int k=0;k<sumconst;k++){
	c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }

}
