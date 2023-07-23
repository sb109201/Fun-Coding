#include<iostream>
#include<fstream>
using namespace std;
int main(){
   auto f=fopen("ex.txt","r");
   if(!f){
     throw"failed to open file!";
   }
   int n;
   fscanf(f,"%d",&n);
   cout<<"number of vertices="<<n<<"\n";
   int adj[n][n];
   cout<<"matrix="<<"\n";
   for(int j=0;j<n;++j){
       for(int i=0;i<n;++i){
           fscanf(f,"%d",&adj[j][i]);
           cout<<adj[j][i]<<" ";
           }
       cout<<"\n";
   }
   int c=0;
   for(int j=0;j<n;j++){
      for(int i=0;i<n;i++){
           c+=adj[j][i];
      }
   }
   int d=0;
   for(int j=0;j<n;j++){
       for(int i=0;i<n;i++){
          d+=adj[j][i];
       }
   }
   cout<<"no.of edges="<<c/2<<"\n"<<"total no.of degrees="<<d<<"\n";
   fclose(f);
   return 0;
}

