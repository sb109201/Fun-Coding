#include<stdio.h>
int n,w[10][10];
void readGraph(){
     FILE *fp;
     fp=fopen("graph.txt","r");
     if(fp==NULL){
      printf("file open failed \n");
      return;
     }
     fscanf(fp,"%d",&n);
     int i,j;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
         fscanf(fp,"%d",&w[i][j]);
         }
      }
      fclose(fp);   
}
void showgraph(){ 
     int i,j;
     for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         printf("%3d",w[i][j]);
       }
       printf("\n");
    }
}
int dist[10];
int pred[10];
int sptset[10];
int mindist(){
    int min=9999;
    int minindex=-1,i;
    for(i=0;i<n;i++){
        if(sptset[i]==0){
           if(min>dist[i]){
              min=dist[i];
              minindex=i;
              }
          }
     }
   return minindex;
}
void dijsktra(int r){
    int i,v;
    for(i=0;i<n;i++){
        dist[i]=9999;
        pred[i]=-1;
        sptset[i]=0;
    }
    dist[r]=0;
    for(i=0;i<n;i++){
       int u=mindist();
       sptset[u]=1;
       for(v=0;v<n;v++){
         if(w[u][v]!=0){
             if(sptset[v]==0 && dist[v]>w[u][v]){
                 dist[v]=w[u][v];
                 pred[v]=u;
                 }
             }
         }
    }
}
void showpath(int dest){
     if(dest==-1)
       return;
     else{
        showpath(pred[dest]);
        printf("%4c",dest+'A');
     }
}
void showtree(){
     int i;
     for(i=0;i<n;i++){
        if(pred[i]!=-1)
        printf("%c->%c,%d\n",pred[i]+'A',i+'A',w[pred[i]][i]);
	}
}
int main(){
	readGraph();
	showgraph();
	dijsktra(0);
	for(int i=1;i<n;i++){
	   printf("path from A to %c",i+'A');
	   showpath(i);
	   printf("\t cost=%d\n",dist[i]);
	}
	return 0;
}
