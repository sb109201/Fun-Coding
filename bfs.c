#include<stdio.h>
#include<stdlib.h>
int v[10]={0};
int n,m[50][50];
int q[50],f=-1,r=-1,s[10],top=-1;
void insert(int item){
	if(f==-1){
		f=r=0;
	}
	q[r++]=item;
}
int delete(){
	return q[f++];
}
void push (int c){
	s[++top] = ;
}
int pop(){
	return(s[top--]);
}

void bfs(int s){
	int u,i;
	v[s]=1;
	insert(s);
	while(f!=r){
		u=delete();
		printf("%c",(u+65));
		for(i=0;i<n;i++){
			if(m[i][u]==1 && v[i]==0){
				insert(i);
				v[i]=1;
			}
		}
	}
}
void prims
int main(){
	int i,j,s;
	FILE *fp;
	fp=fopen("graph.txt","r");
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			fscanf(fp,"%d",&m[i][j]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("	%d",m[i][j]);
		}
		printf("\n");
	}
	printf("Enter the vertex: ");
	scanf("%d",&s);
	printf("BFS: ");
	bfs(s);
}
