#include<stdio.h>
int p[]={2,3,5,2,4};
int M[20][20]={0};
int S[20][20]={0};
int n=sizeof(p)/sizeof(p[0])-1;
void displayMtable(){
	printf("Mtable:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		 printf("%5d",M[i][j]);
		printf("\n");
	}
}
void displayStable(){
	printf("Stable:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		 printf("%5d",S[i][j]);
		printf("\n");
	}
}
void pop(int i,int j){
	if(i==j)
	 printf("A%d",i);
	else{
		printf("(");
		pop(i,S[i][j]);
		pop(S[i][j]+1,j);
		printf(")");
	}
}
void matrixchainorder(){
	for(int i=1;i<=n;i++)
	 M[i][i]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			M[i][j]=9999;
			for(int k=i;k<j;k++){
				int cost=M[i][k]+M[k+1][j]+p[i-1]*p[j]*p[k];
				if(cost<M[i][j]){
					M[i][j]=cost;
					S[i][j]=k;
				}
			}
		}
	}
	displayMtable();
	displayStable();
}
int main(){
	matrixchainorder();
	pop(1,4);
	printf("\n");
	return 0;
}






















