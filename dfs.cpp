#include <iostream>
#include <stdlib.h>
#define size 10
using namespace std;
int graph[size][size],n;
char a[size];
class stack
{
    public:
    int top=-1;
    int isFull()
	{
		if(top==size-1)
			return 1;
		else
			return 0;
	}
	int isEmpty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	void push(char ch)
	{
		if(isFull())
			return;
		else
		    top++;
		a[top]=ch;
	}
	char pop()
	{
		char ch;
		if(isEmpty())
			return '#';
		else
		    ch=a[top--];
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
	void DFS(char v)
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
    stack ob;
    ob.readGraph();
    ob.displaygraph();
    cout<<"The DFS traversal:\n";
    ob.DFS('A');
    return 0;
}
