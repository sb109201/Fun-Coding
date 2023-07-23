#include<iostream>
using namespace std;
int digits(int n){
    if(n==0)
    return 0;
    return ((n%10)+digits(n/10));
}
int main(){
   int n;
   cout<<"enter a number=";
   cin>>n;
   int s=digits(n);
   cout<<"the sum is="<<s;
   return 0;
}
