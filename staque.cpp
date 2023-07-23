#include<iostream>
using namespace std;
int s1[100],s2[100],top1=-1,top2=-1;

int main(){
  int c,l;
  do{
  cout<<"enter 1.insert 2.remove 3.display";
  cin>>c;
  switch(c){
   case 1:insert();
          break;
   case 2:remove();
          break;
   case 3:display();
          break;
   default: cout<<"invalid choice";
  }
  cout<<"enter 0 to continue and 1 to exit";
  cin>>l;
 }while(l==0);
 return 0;
}
