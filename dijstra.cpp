#include<stdio.h>

int n,w[10][10];

void readGraph()
{
	FILE *fp;
	fp=fopen("graph1.txt","r");
	if(fp==NULL)
	{
		printf("File open failed\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

void showGraph()
{
	int i,j;
	printf("The graph:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%3d",w[i][j]);
		}
		printf("\n");
	}
}

int dist[10];
int pred[10];
int sptSet[10];

int mindist(){
	int min=9999;
	int minIndex=-1,i;
	for(i=0;i<n;i++)
	{
		if(sptSet[i]==0)
		{
			if(min>dist[i])
			{
				min=dist[i];
				minIndex=i;
			}
		}
	}
	return minIndex;
}

void Dijkstra(int r)
{
	int i,v;
	for(i=0;i<n;i++)
	{
		dist[i]=9999;
		pred[i]=-1;
		sptSet[i]=0;
	}
	dist[r]=0;
	for(i=0;i<n;i++)
	{
		int u=mindist();
		sptSet[u]=1;
		for(v=0;v<n;v++)
		{
			if(w[u][v]!=0){
				if(sptSet[v]==0 && w[u][v]+dist[u]<dist[v])
				{
					dist[v]=w[u][v]+dist[u];
					pred[v]=u;
				}
			}
		}
	}
}
void display(int i){
	if(i==-1) return;
	else{
		display(pred[i]);
		printf("%4c",i+'A');
	}
}
int main(){
    int min=9999,t;
	readGraph();
	showGraph();
	Dijkstra(0);
	for(int i=1;i<n;i++){
		printf("Path from A to %c:",i+'A');
		display(i);
		printf(" ------>");
		printf(" Cost=%d\n",dist[i]);
		if(min>dist[i])
		{
		    min=dist[i];
		    t=i;
		}
	}
	printf("\nPath with minimum cost is A to %c:",t+'A');
	display(t);
	printf(" ------>");
	printf(" Cost=%d\n",min);
	return 0;
}
