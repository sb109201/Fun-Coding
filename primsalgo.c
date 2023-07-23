#include<stdio.h>
#include<stdlib.h>
int mk(int key,int MST){
	int least = int_MAX;
	for(int v=0;v<n;v++){
		if(MST[v]==0 && key[v]>least){
			least = key[v];
			minIndex = i;
		}
	}
	return minIndex;
}
void print_MST(int graph [][],int parent[]){
	for(int i =0;i<n;i++){
		printf("%d %d=%d",parent[i],i,graph[parent [i][i]]);
	}
}
void prims(int graph [][], int n){
	int key[n];
	int MST[n];
	int p[n];
	for(i=0;i<n;i++){
		key[i]=INT_MAX;
		MST[i]=0;
	}
	key[0]=0;
	p[0]=-1;
	for(int c= 0;c<n;c++){
		int u = mk(key,MST);
		MST[u]= 1;
		for(int v= 0;v<n;v++){
			if(graph[u][v] > 0 && MST[[v]== 0 && graph[u][v]>key [v]){
				key[v]=graph[u][v];
				parent[v]=u;
			}
		}
	}
	print_MST(graph,parent);
}
int main(){
	int i,j,n;
	FILE *fp;
	fp=fopen("graph.txt","r");
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			fscanf(fp,"%d",&graph[i][j]);
	}
	prims(graph,n);
}
