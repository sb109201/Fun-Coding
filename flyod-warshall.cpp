#include<iostream>
using namespace std;
int w[10][10];
int n;
void readGraph()
{
	FILE *fp;
	fp=fopen("flyod-graph.txt","r");
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
int dist[10][10];
int pred[10][10];
void Floyd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=w[i][j];
            if(w[i][j]==0||w[i][j]==999){
                pred[i][j]=-1;
            }
            else pred[i][j]=i;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=999 && dist[k][j]!=999){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                        pred[i][j]=pred[k][j];
                    }
                }
            }
        }
    }
}


void APSP(int i,int j){
    if(i==j)
        cout<<"    "<<(char)(i+'A');
    //else if(pred[i][j]==-1) 
    //    cout<<"NO PATH"<<endl;
    else{
        APSP(i,pred[i][j]);
        cout<<"    "<<(char)(j+'A');
    }
}
int main(){
    readGraph();
    Floyd();
    for(int i=0;i<n;i++)
    {
        cout<<"Source vertex:"<<(char)(i+65)<<endl;
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            cout<<"Path from "<<(char)(i+65)<<" to "<<(char)(j+65)<<":";
            APSP(i,j);
            cout<<"-----> Cost="<<dist[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
