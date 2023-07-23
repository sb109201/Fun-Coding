#include<iostream>
#include<fstream>
using namespace std;
char arr[20];
class Queue{
     public:
     int f=-1,r=-1;
     int Full(int r,int s){
      if(r==s-1)
        return 1;
      return 0;
     }
     int Empty(){
       if(f==-1)
          return 1;
       return 0;
     }
     void enterQ(char c){
         if(Full(r,s))
           return 0;
         if(f==-1){
            f=0;
            r=0;
         }
         else{
          r++;
          arr[r]=c;
         }
     }
     char removQ(){
        char c;
        if(Empty())
          return 0;
        c=arr[f];
        if(f==r){
        f=-1;r=-1;
        }
        else
         f++;
       return c;
      }
     void Bfs(char ch,int*graph,int s){
           int visited[s],i;
           char u;
           for(i=0;i<s;i++)
               visited[i]=0;
           enterQ(ch);
           visited[ch-65]=1;
           while(!Empty()){
              u=removQ();
              cout<<u<<" ";
              for(i=0;i<s;i++){
                 if(graph[u-65][i]==1){
                   if(visited[i]==0){
                       visited[i]=1;
                       enterQ((char)(65+i));
                     }
                  }
              }
          }
     cout<<'\n'; 
  }
};
int main(){
    Queue ob;
    fstream infile;
    infile.open("ex.txt",ios::in);
    if(!infile){
       cout<<"\n error to open file\n";
    exit(1); 
   }
   int n;
   infile>>n;
   int graph[n][n];
   int i,j;
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
          infile>>graph[i][j];
       }
   }
   infile.close();
   int m,k;
   cout<<"the adjacency matrix:\n";
   for(m=0;m<n;m++){
       for(k=0;k<n;k++){
          cout<<graph[m][k];
       }
     cout<<"\n";
   }
   cout<<"the bfs traversal:\n";
   ob.Bfs('A',graph,n);
   return 0;
}
