#include<stdio.h>
#include<stdlib.h>
int n,c=1,x[128];
int safeplace(int k,int i){
	int j;
	for(j=1;j<=k-1;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
			return 0;
		}
	}
	return 1;
	
}
void print(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(x[i]==j)
			 printf(" Q ");
			else
			 printf(" _ ");
		}
	printf("\n");
	}
	
}
void nqueen(int k,int n){
	int i;
	for(i=1;i<=n;i++){
		if(safeplace(k,i)==1){
			x[k]=i;
			if(k==n){
			 printf("\n\nSolution %d :-\n\n",c++);
			 print();
		    }
			else
			 nqueen(k+1,n);
		}
	}
}
	 
int main(){
	printf("Enter rows(columns) of chessboard:\n");
	scanf("%d",&n);
	nqueen(1,n);
	return 0;
}
























