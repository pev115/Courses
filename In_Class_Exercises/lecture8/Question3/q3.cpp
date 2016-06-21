#include<iostream>
#include<cstdlib>

using namespace std;

int gcd(int m, int n);

int main(){
  int m;
  int n;
  int GCD;

  cout<< "Enter two integers separated by a space : ";
  cin>>m >>n;
  
  GCD = gcd(m,n);
  
  cout<<"The gcd is " <<GCD<<endl<<endl;
  return 0;

}

int gcd(int m,int n){
  
  int k;

  if (n<0|| m<0 || (m ==0 && n==0)){
    cout<<"AAAAARRRGGGHHG!!! ...___... ...___... ...___..."<<endl<<endl;
    exit(1);
  }
  
  if(n==0){return m;}
  else if(m==0){return n;}
  
  if( m>=n){
    k= m-n;
    return gcd(n,k);
  } else if (n>m){
    k=n-m;
   return gcd(m,k);
  }
  
  cout<<endl<<endl<<"oh oh....."<<endl<<endl;
  exit(1);
  
}
