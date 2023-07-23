#include<iostream>
#include<fstream>
using namespace std;
int n;
void readGraph(){
   fstream input;
   input.open("graph.txt",ios::in);
   input>>n;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          int num;
          input>>num;
          if(num!=0){
          edge[edgeCount].v1=i;
          edge[edgeCount].v2=j;
          edge[edgeCount++].weight=num;
          }
      }
   }
   input.close();
}
int minkey(int key[],bool visited[]){
    int min=
}
