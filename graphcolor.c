#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 4
int G[n+1][n+1],m,c=1,check=0;
int X[n+1]={0};
int i,j;
void display(){
	printf("\n \nSolution %d:\n",c++);
	for(i=1;i<=n;i++){
		printf("%d\n",X[i]);
		if(X[i]>0){
			check++;
		}
	}
}
void nextValue(int k){
	int j;
	do{
		X[k]=(X[k]+1)%(m+1);
		if(X[k]==0)
		 return;
		for(j=1;j<=k-1;j++){
			if(G[k][j]==1 && X[k]==X[j])
			 break;
		}
		if(j==k)
		 return;
	}while(true);
}
void mColoring(int k){
	do{
		nextValue(k);
		if(X[k]==0)
		 return;
		if(k==n)
		 display();
		else
		 mColoring(k+1);
		
	}while(true);
}
void main()
{
    FILE *fp;
    fp=fopen("color.txt","r");
    if(fp==NULL){
        printf("\nError in opening the file !\n");
        exit(1);
    }
    fscanf(fp,"%d",&G[0][0]);
    for( i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&G[i][j]);

    printf("\n   -------- GRAPH COLORING --------\n\n");
    printf("\nEnter the number of colours : ");
    scanf("%d",&m);
    if(m>=1)
    {
        mColoring(1);
        if(check==0)
            printf("\n\nSorry.The graph needs more than %d colour(s) for proper coloring.",m);
    }
    else
    printf("\nInvalid Input.");
}
