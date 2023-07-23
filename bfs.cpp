#include <iostream>
#include <stdlib.h>
#define size 7
using namespace std;
int graph[size][size],n;
char a[size];
class queue
{
    public:
    int front=-1,rear=-1;
    int isFull()
	{
		if(rear==size-1)
			return 1;
		else
			return 0;
	}
	int isEmpty()
	{
		if(front==-1)
			return 1;
		else
			return 0;
	}
	void push(char ch)
	{
		if(isFull())
			return;
		if(front==-1)
		{
		    front=0;
		    rear=0;
		}
		else
		    rear++;
		a[rear]=ch;
	}
	char pop()
	{
		char ch;
		if(isEmpty())
			return '#';
		ch=a[front];
		if(front==rear)
		{
		    front=-1;rear=-1;
		}
		else
		    front++;
		return ch;
	}
	void readGraph()
    {
    	FILE *fp;
    	fp=fopen("bfs-dfs-graph.txt","r");
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
    			fscanf(fp,"%d",&graph[i][j]);
    		}
    	}
    	fclose(fp);
    }
	void BFS(char v)
	{
	    int visited[size];
	    int i;
	    char u;
	    for(i=0;i<size;i++)
	        visited[i]=0;
	    push(v);
	    visited[v-65]=1;
	    while(!isEmpty())
	    {
	        u=pop();
	        cout<<u<<" ";
	        for(i=0;i<size;i++)
	        {
	            if(graph[u-65][i]==1)
	            {
	                if(visited[i]==0)
	                {
	                    visited[i]=1;
	                    push((char)(65+i));
	                }
	            }
	        }
	    }
	    cout<<endl;
	}
	void displaygraph()
	{
	    int i,j;
        cout<<"The adjacency matrix:\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
	}
};
int main()
{
    queue ob;
    ob.readGraph();
    ob.displaygraph();
    cout<<"The BFS traversal:\n";
    ob.BFS('A');
    return 0;
}

