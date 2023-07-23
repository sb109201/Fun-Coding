#include<iostream>
using namespace std;
int top=-1,a[100];
int isFull(){
     if(top>=100)
     return 1;
     else
     return 0;
}
int isEmpty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(){
   int n;
   if(isFull())
   cout<<"stack overflow";
   else{
   cout<<"enter the number=";
   cin>>n;
   top++;
   a[top]=n; 
   }
}
void pop(){
    if(isEmpty())
    cout<<"stack underflow";
    else
    top--;
}
int peek(){
   int n;
   n=a[top];
   return n;
}
void display(){
    cout<<"the elements in the stack are=\n";
   for(int i=top;i>=0;i--){
       cout<<a[i]<<"\n";
   }
}
int main(){
   int c,b,l;
   do{
   cout<<"enter 1.push 2.pop 3.peek 4.display";
   cin>>c;
   switch(c){
   case 1:push();
          break;
   case 2:pop();
          break;
   case 3:b=peek();
          cout<<"the peek element of the stack is="<<b;
          break;
   case 4:display();
          break;
   default: cout<<"invalid choice";
   }
   cout<<"press 0 to continue and 1 to exit";
   cin>>l;
 }while(l==0);
   return 0;
}
