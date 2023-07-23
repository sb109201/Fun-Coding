#include<iostream>
using namespace std;
int front=-1,rear=-1,a[100];
 int isFull(){
   if(rear>=100)
   return 1;
   else
   return 0;
 }
 int isEmpty(){
   if((front+1)>=rear || (rear==-1))
   return 1;
   else 
   return 0;
 }
 void insert(){
     int n;
     if(isFull())
     cout<<"queue overflow";
     else{
       cout<<"enter a number=";
       cin>>n;
       if(front==-1)
       front++;
       rear++;
       a[rear]=n;
     } 
}
 void remove(){
    if(isEmpty())
    cout<<"queue underflow";
    else
    front++;
 }
 void display(){
    for(int i=front;i<=rear;i++)
    cout<<a[i]<<"\n";
 }
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

