

/*	
#include <stdio.h>
struct Edge
{
    int v1;
    int v2;
    int weight;
};
struct Edge edge[100];
int noV,noE=0;
void readGraph()
{
    FILE *fp;
    fp=fopen("prims-kruskal-graph.txt","r");
    if(fp==NULL)
    {
        printf("File open failed\n");
        return;
    }
    fscanf(fp,"%d",&noV);
    for(int i=0;i<noV;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int x;
            fscanf(fp,"%d",&x);
            if(x!=0)
            {
               edge[noE].v1=j;
               edge[noE].v2=i;
               edge[noE++].weight=x;
            }
        }
    }
    fclose(fp);
}
void showGraph()
{
    int i;
    for(i=0;i<noE;i++)
    {
        printf("(%c,%c):%d\n",edge[i].v1+'A',edge[i].v2+'A',edge[i].weight);
    }
}
void bubble()
{
    int i,j;
    for(i=0;i<noE-1;i++)
    {
        for(j=0;j<noE-1-i;j++)
        {
            if(edge[j].weight>edge[j+1].weight)
            {
                struct Edge temp=edge[j];
                edge[j]=edge[j+1];
                edge[j+1]=temp;
            }
        }
    }
}
int parent[100];
int mst[100][3];
int mstE=0;
void makeSet()
{
    for(int i=0;i<noV;i++)
        parent[i]=-1;
}
int find(int i)
{
    while(parent[i]>0) 
        i=parent[i];
    return i;
}
void Union(int i,int j)
{
    int u=find(i);
    int v=find(j);
    parent[u]=v;
}
void kruskal()
{
    bubble();
    makeSet();
    int i;
    for(i=0;i<noE;i++)
    {
        if(find(edge[i].v1)!=find(edge[i].v2))
        {
            Union(edge[i].v1,edge[i].v2);
            mst[mstE][0]=edge[i].v1;
            mst[mstE][1]=edge[i].v2;
            mst[mstE][2]=edge[i].weight;
            mstE++;
        }
    }
}
void showMST()
{
    int i,t=0;
    for(i=0;i<mstE;i++)
    {
        printf("(%c,%c):%d\n",mst[i][0]+'A',mst[i][1]+'A',mst[i][2]);
        t=t+mst[i][2];
    }
    printf("Total weight=%d\n",t);
}
int main()
{
    printf("The edges:\n");
    readGraph();
    showGraph();
    printf("\n\nThe sorted edges:\n");
    kruskal();
    showGraph();
    printf("\n\n");
    printf("The spanning tree:\n");
    showMST();
    return 0;
}*/
#include <stdio.h>
struct Edge
{
    int v1;
    int v2;
    int weight;
};
struct Edge edge[100];
int noV,noE=0;
void readGraph()
{
    FILE *fp;
    fp=fopen("kruskal.txt","r");
    if(fp==NULL)
    {
        printf("File open failed\n");
        return;
    }
    fscanf(fp,"%d",&noV);
    for(int i=0;i<noV;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int x;
            fscanf(fp,"%d",&x);
            if(x!=0)
            {
               edge[noE].v1=j;
               edge[noE].v2=i;
               edge[noE++].weight=x;
            }
        }
    }
    fclose(fp);
}
void showGraph()
{
    int i;
    for(i=0;i<noE;i++)
    {
        printf("(%c,%c):%d\n",edge[i].v1+'A',edge[i].v2+'A',edge[i].weight);
    }
}
void bubble()
{
    int i,j;
    for(i=0;i<noE-1;i++)
    {
        for(j=0;j<noE-1-i;j++)
        {
            if(edge[j].weight>edge[j+1].weight)
            {
                struct Edge temp=edge[j];
                edge[j]=edge[j+1];
                edge[j+1]=temp;
            }
        }
    }
}
int parent[100];
int mst[100][3];
int mstE=0;
void makeSet()
{
    for(int i=0;i<noV;i++)
        parent[i]=-1;
}
int find(int i)
{
    while(parent[i]>0) 
        i=parent[i];
    return i;
}
void Union(int i,int j)
{
    int u=find(i);
    int v=find(j);
    parent[u]=v;
}
void kruskal()
{
    bubble();
    makeSet();
    int i;
    for(i=0;i<noE;i++)
    {
        if(find(edge[i].v1)!=find(edge[i].v2))
        {
            Union(edge[i].v1,edge[i].v2);
            mst[mstE][0]=edge[i].v1;
            mst[mstE][1]=edge[i].v2;
            mst[mstE][2]=edge[i].weight;
            mstE++;
        }
    }
}
void showMST()
{
    int i,t=0;
    for(i=0;i<mstE;i++)
    {
        printf("(%c,%c):%d\n",mst[i][0]+'A',mst[i][1]+'A',mst[i][2]);
        t=t+mst[i][2];
    }
    printf("Total weight=%d\n",t);
}
int main()
{
    printf("The edges:\n");
    readGraph();
    showGraph();
    printf("\n\nThe sorted edges:\n");
    kruskal();
    showGraph();
    printf("\n\n");
    printf("The spanning tree:\n");
    showMST();
    return 0;
}
