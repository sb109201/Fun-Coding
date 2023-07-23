/*#include<stdio.h>
int j[50],p[50],d[50],k;
int js(int);
int main(){
	int n,a,i,j1,sum=0,temp1,temp2;
	printf("Enter no of jobs:\n");
	scanf("%d",&n);
	printf("Enter profit dataset:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter deadline dataset:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	//bubble sort
	for(i=1;i<=n;i++){
		for(j1=1;j1<=n;j1++){
			if(p[j1]<p[j1+1]){
				temp1=p[j1];
				p[j1]=p[j1+1];
				p[j1+1]=temp1;
				temp2=d[j1];
				d[j1]=d[j1+1];
				d[j1+1]=temp2;
			}
		}
	}
	printf("Job deadline profit:\n");
	for(i=1;i<=n;i++){
		printf("j[%d]-->%d-->%d",i,d[i],p[i]);
	}
	a=js(n);
	printf("\nAvailable jobs:%d\n",a);
	printf("Job sequences:\n");
	for(i=1;i<=k;i++){
		printf("%d--->",j[i]);
	}
	printf("NULL");
	printf("\n");
	for(i=1;i<=k;i++){
		sum+=p[i];
	}
	printf("Profit:%d\n",sum);
	return 0;
}
int js(int n){
	int i,r,q;
	d[0]=j[0]=0;
	j[1]=1;
	k=1;
	for(i=2;i<=n;i++){
		r=k;
		while(d[j[r]]>d[i] && d[j[r]]!=r){
			r=r-1;
		}
		if(d[j[r]]<=d[i] && d[i]>r){
		  for(q=k;q<=(r+1);q--){
			j[q+1]=j[q];
		  }
		  j[r+=1]=i;
		  k=k+1;
	   }
	}
	return k;
}*/
/*#include<iostream>
using namespace std;
int i,temp;
void adjustheap(int a[],int i,int n){
	int large,temp;
	large=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[large]<a[l])
	 large=l;
	if(r<n && a[large]<a[r])
	 large=r;
	if(large!=i){
		temp=a[i];
		a[i]=a[large];
		a[large]=temp;
		adjustheap(a,large,n);
	}
}
void makeheap(int a[],int n){
	for(i=(n/2)-1;i>=0;i--)
	 adjustheap(a,i,n);
}
void heapsort(int a[],int n){
	makeheap(a,n);
	for(i=(n-1);i>=1;i--){
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		adjustheap(a,0,i);
	}
}
int main(){
	int n,a[n];
	cout<<"Size";
	cin>>n;
	cout<<"elements";
	for(i=0;i<n;i++)
	 cin>>a[i];
	cout<<"before";
	for(i=0;i<n;i++)
	 cout<<a[i];
	heapsort(a,n);
	cout<<"after";
	for(i=0;i<n;i++)
	 cout<<a[i];
	return 0;
}
*/
/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 4
int G[n+1][n+1],c=1,check=0,m;
int X[n+1]={0};
void display(){
	printf("\n\nSolution%d:\n",c++);
	for(int i=1;i<=n;i++){
        printf("%d\n",X[i]);
        if(X[i]>0)
         check++;
    
	}
}
void nextvalue(int k){
	do{
		int j;
		X[k]=(X[k]+1)%(m+1);
		if(X[k]==0)
		 return;
		for(j=1;j<=k-1;j++)
		 if(G[k][j]==1 && X[k]==X[j])
		  break;
		if(j==k)
		 return;
	}while(true);
}
void mcoloring(int k){
	do{
		nextvalue(k);
		if(X[k]==0)
		 return;
		if(k==n)
		  display();
		else
		 mcoloring(k+1);
		 
	}while(true);
}
int main(){
	FILE*fp;
	fp=fopen("color.txt","r");
	if(fp==NULL){
		printf("File opened failed\n");
		exit(1);
		
	}
	fscanf(fp,"%d",&G[0][0]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fscanf(fp,"%d",&G[i][j]);
	printf("Grpah coloring:\n");
	printf("color:");
	scanf("%d",&m);
	if(m>=1){
		mcoloring(1);
		if(check==0)
		 printf("%d more neede",m+1);
	}
	else
	 printf("Invalid input");
		
	return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
int c=1,n,x[128],j,k,i;
int safeplace(int k,int i){
	for(j=1;j<=k-1;j++){
		if(x[j]==i) || abs(j-k)==abs(x[j]-i)){
			return 0;
		}
	}
	return 1;
}
void print(){
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(x[i]==j){
				printf("Q");
			}
			else
			 printf("_");
		}
		printf("/n");
	}
}
void nqueen(int k,int n){
	for(i=1;i<=n;i++){
		if(safeplace(k,i)==1){
			x[k]=i;
			if(j==k){
				printf("\n\nSolution%d:\n\n");
				print();
			}
			else
			 nqueen(k+1,n);
		}
	}
}
int main(){
	printf("rows or columns:");
	scanf("%d",&n);
	nqueen(1,n);
	return 0;
}*/
/*#include<stdio.h>
int k,n,d[50],j[50],p[50];
int js(int);
int main(){
	int temp1,temp2,k,i,j1,a,sum=0;
	printf("jobs:\n");
	scanf("%d",&n);
	printf("profit\n");
	for(i=1;i<=n;i++)
	 scanf("%d",&p[i]);
	printf("deadline\n");
	for(i=1;i<=n;i++)
	 scanf("%d",&d[i]);
	//bubble sort
	for(i=1;i<=n;i++){
		for(j1=1;j1<=n-i;j1++){
			if(p[j1]<p[j1+1]){
				temp1=p[j1];
				p[j1]=p[j1+1];
				p[j1+1]=temp1;
				temp2=d[j1];
				d[j1]=d[j1+1];
				d[j1+1]=temp2;
			}
		}
	}
	printf("Job profit deadline:\t");
	for(i=1;i<=n;i++)
	 printf("j[%d] %d %d\t",i,p[i],d[i]);
	a=js(n);
	printf("available jobs:%d",a);
	printf("job sequences:\n");
	for(i=1;i<=n;i++){
	 printf("%d-->",j[i]);
}
	printf("NULL");
	printf("\n");
	for(i=1;i<=n;i++)
	 sum+=p[i];
	printf("profit:%d",sum);

}
int js(int n){
	int i,r,q;
	d[0]=j[0]=0;
	j[1]=1;
	k=1;
	for(i=2;i<=n;i++){
		r=k;
		while(d[j[r]]>d[i] && d[j[r]]!=r){
			r=r-1;
		}
		if(d[j[r]]<=d[i] && d[i]>r){
			for(q=k;q<=(r+1);q++){
				j[q+1]=j[q];
			}
			j[r+=1]=i;
			k=k+1;
		}
	
	}
	return k;
}*/
/*#include<stdio.h>
void knapsack(int n,float w[],float p[],float c){
	int i;
	int u=c;
	float x[20],tp=0;
	for(i=0;i<n;i++)
	 x[i]=0.0;
	for(i=0;i<n;i++){
		if(w[i]>u)
			break;
		else{
			x[i]=1.0;
			//u=u-w[i];
			tp=tp+p[i];
			u=u-w[i];

		}
}
	if(i<=n){
		x[i]=u/w[i];
		tp=tp+x[i]*p[i];
	}
	printf("Vectors:\n");
	for(i=0;i<n;i++)
	 printf("%.2f\n",x[i]);
	printf("max profit:%.2f\n",tp);

}

int main(){
	float w[20],p[20],r[20],c;
//	float weight[]=w[],profit[]=p[];

	int n,temp,i,j;
	printf("Objects:\n");
	scanf("%d",&n);
	printf("profit and weight:\n");
	for(i=0;i<n;i++)
	 scanf("%f%f",&p[i],&w[i]);
	printf("capacity:\n");
	scanf("%d",&c);
	for(i=0;i<n;i++)
	 r[i]=p[i]/w[i];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(r[i]<r[j]){
				temp=r[j];
				r[j]=r[i];
				r[i]=temp;
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=w[j];
				w[j]=w[i];
				w[i]=temp;
			}
		}
	}
	printf("profit weight ratio:\n");
	for(i=0;i<n;i++)
	 printf("%.2f\t %.2f\t %.2f\n",p[i],w[i],r[i]);
	knapsack(n,w,p,c);
}*/
/*#include<stdio.h>
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
*/
/*#include<iostream>
using namespace std;
#define size 10
int g[size][size],n;
char a[size];
class queue{
	public:
	int front=-1,rear=-1;
	int isFull(){
		if(rear==size-1)
		 return 1;
		else
		 return 0;
	}
	int isEmpty(){
		if(front==-1)
		 return 1;
		else
		 return 0;
	}
	void push(char ch){
		if (isFull())
		 return;
		if(front==-1){
			front=0;rear=0;
		}
		else
		 rear++;
		 a[rear]=ch;
	}
	char pop(){
		char ch;
		if(isEmpty())
		 return '#';
		 ch=a[front];
		if(front==rear){
			front=-1;rear=-1;
		}
		else
          front++;
		return ch;
	}
	void readgraph(){
		FILE*fp;
		fp=fopen("bfs-dfs-graph.txt","r");
		if(fp==NULL)
		 cout<<"File opened failed\n";
		fscanf(fp,"%d",&n);
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				fscanf(fp,"%d",&g[i][j]);
			}
		}
		fclose(fp);
	}
	void bfs(char v){
		int i,visited[size];
		char u;
		for(i=0;i<size;i++)
		 visited[i]=0;
		push(v);
		visited[v-65]=1;
		while(!isEmpty()){
			u=pop();
			cout<<u<<" ";
			for(i=0;i<size;i++){
				if(g[u-65][i]==1){
					if(visited[i]==0){
						visited[i]=1;
						push((char)(i+65));
					}
				}
			}
		}
	}
	
	void display(){
		int i,j;
		cout<<"Adjacent matrix:\n";
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
			 cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
int main(){
	queue ob;
	ob.readgraph();
	ob.display();
	cout<<"The BFS traversal:\n";
	ob.bfs('A');
	return 0;
}*/
/*#include<iostream>
using namespace std;
struct Edge{
	int  v1,v2,weight;
};
int w[4][4]={0,10,8,999,999,0,-6,999,999,999,0,2};
int n=4,i,j;
void readgraph(){
	FILE*fp;
	fp=fopen("bellmanford-graph.txt","r");
	if(fp==NULL)
	 cout<<"not open";
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
				fscanf(fp,"%d",&w[i][j]);

		}
	}
	fclose(fp);
}
struct Edge edge[4]={{0,1,10},{1,2,-6},{0,2,8},{2,3,2}};
int pred[20],dist[20],noe,nov;
void bf(int src){
	for(i=0;i<nov;i++){
		dist[i]=999;
		pred[i]=-1;
	}
	dist[src]=0;
	for(i=1;i<nov-1;i++){
		for(j=0;j<noe;j++){
			int u=edge[j].v1;
			int v=edge[j].v2;
			if(dist[u]+w[u][v]<dist[v]){
				dist[v]=dist[u]+w[u][v];
				pred[v]=u;
			}
		}
	}
	 
}
void displaypath(int i){
	if(i==-1)
	 return;
	else{
		displaypath(pred[i]);
		cout<<" "<<(char)(i+'A');
	//	cout<<endl;
	}
}
int main(){
	cout<<"vertex";
	cin>>nov;
	cout<<"edge";
	cin>>noe;
	bf(0);
	for(i=1;i<nov;i++){
		cout<<"path from A to "<<(char)(i+65)<<" :";
		displaypath(i);
		cout<<"-->Cost"<<dist[i];
		
	}
	cout<<endl;
	return 0;
}*/
/*#include<iostream>
using namespace std;
int w[10][10],n,i,j,k;
void readgraph(){
	FILE*fp;
	fp=fopen("flyod-graph.txt","r");
	if(fp==NULL)
	 cout<<"not open";
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				fscanf(fp,"%d",&w[i][j]);

		}
	}
	fclose(fp);
}
int dist[10][10],pred[10][10];
void fw(){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			dist[i][j]=w[i][j];
			if(w[i][j]==0 || w[i][j]==999)
			 pred[i][j]=-1;
			else
			 pred[i][j]=i;
		}
	}
	for(k=0;k<n;k++){
	 for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(dist[i][k]!=999 && dist[k][j]!=999){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
				 dist[i][j]=dist[i][k]+dist[k][j];
				 pred[i][j]=pred[k][j];
				}
			}
		}
	}
	}
}
void displaypath(int i,int j){
	if(i==j)
	 cout<<" "<<(char)(i+'A');
	else{
		displaypath(i,pred[i][j]);
		cout<<" "<<(char)(j+'A');
	}
}
int main(){
		readgraph();
		fw();
		for(i=0;i<n;i++){
			cout<<"source"<<(char)(i+65)<<" ";
			for(j=0;j<n;j++){
				if(i==j)
				 continue;
				cout<<"path from"<<(char)(i+65)<<" to"<<(char)(j+65)<<" ";
				displaypath(i,j);
				cout<<"cost"<<dist[i][j]<<endl;
			}
		}
}*/
/*#include<stdio.h>
int max,min;
int a[100];
void maxmin(int i,int j){
	int max1,min1,mid;
	if(i==j){
		max=min=a[i];
	}
	else{
		if(i==j-1){
			if(a[i]<a[j]){
				max=a[j];min=a[i];
			}
			else{
				max=a[i];min=a[j];
			}
		}
		else{
			mid=(i+j)/2;
			maxmin(i,mid);
			max1=max;min1=min;
			maxmin(mid+1,j);
			if(max<max1)
			 max=max1;
			if(min>min1)
			 min=min1;
		}
	}
	
}
int main(){
	int i,n;
	printf("Enter number of total numbers:");
	scanf("%d",&n);
	printf("numbers:");
	for(i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	max=a[0];min=a[0];
	maxmin(1,n);
	printf("Min:%d\n",min);
	printf("Max:%d\n",max);
	return 0;
}*/
/*#include<iostream>
using namespace std;
int partition(int a[],int s,int e){
	int pivot=a[e];
	int pi=s;
	for(int i=s;i<e;i++){
		if(a[i]<pivot){
			int temp=a[i];
			a[i]=a[pi];
			a[pi]=temp;
			pi++;
			
		}
	}
	int temp=a[e];
	a[e]=a[pi];
	a[pi]=temp;
	return pi;
}
void qs(int a[],int s,int e){
	if(s<e){
		int p=partition(a,s,e);
		qs(a,s,p-1);
		qs(a,p+1,e);
	}
}
int main(){
	int n,i;
	cout<<"Array size:";
	cin>>n;
	int a[n];
	cout<<"elements";
	for(i=0;i<n;i++)
	 cin>>a[i];
	cout<<"before:";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	qs(a,0,n-1);
	cout<<"After:";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	return 0;
}*/
/*#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int r,int s){
	int i=l;
	int j=m+1;
	int k=l;
	int temp[s];
	while(i<=m && j<=r){
		if(a[i]<=a[j]){
			temp[k]=a[i];
			i++;
			k++;
		}
		else{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=m){
		temp[k]=a[i];
		i++;
		k++;
		
	}
	while(j<=r){
		temp[k]=a[j];
		j++;
		k++;
	}
	for(int p=l;p<=r;p++)
	 a[p]=temp[p];
}
void ms(int a[],int l,int r,int s){
	if(l<r){
		int m=(l+r)/2;
		ms(a,l,m,s);
		ms(a,m+1,r,s);
		merge(a,l,m,r,s);
	}
}
int main(){
	int i,n;
	cout<<"size";
	cin>>n;
	int a[n];
	cout<<"elements";
	for(i=0;i<n;i++)
	 cin>>a[i];
   cout<<"before";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";	
	ms(a,0,n-1,n);
	cout<<"after";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	 return 0;
}
*/
/*#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int grp(int low,int high){
	srand(time(NULL));
	return low+rand()%(high-low+1);
}
void qs(int a[],int low,int high){
	if(low<high){
		int pi=grp(low,high);
		int pivot=a[pi];
		swap(a,pi,high);
		int i=low-1;
		for(int j=low;j<high;j++){
			if(a[j]<pivot){
				i++;
				swap(a,i,j);
			}
		}
		swap(a,i+1,high);
		qs(a,low,i);
		qs(a,i+2,high);
	}
}
int main(){
	int n,i,a[n];
	cout<<"array";
	cin>>n;
	cout<<"elements";
	for(i=0;i<n;i++)
	 cin>>a[i];
	cout<<"before";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	qs(a,0,n-1);
	cout<<"after";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
}*/
/*#include<iostream>
using namespace std;
int bs(int a[],int num,int beg,int end){
	if(beg>end)
	 cout<<"Number not found";
	else{
		int mid=(beg+end)/2;
		if(a[mid]==num)
		 cout<<"NUmber found at"<<mid<<"index";
		else if(num<a[mid])
		 bs(a,num,beg,mid-1);
		else if(num>a[mid])
		 bs(a,num,mid+1,end);
	}
}
int main(){
	int s,a[s],num;
	cout<<"array size";
	cin>>s;
	cout<<"elements";
	for(int i=0;i<s;i++)
    	cin>>a[i];
    cout<<"number to found:";
    cin>>num;
    int beg=0,end=s-1;
    bs(a,num,beg,end);
    return 0;
}*/
/*#include<iostream>
using namespace std;
int search(int a[],int l,int r,int key){
	if(r>=l){
		int mid1=l+(r-1)/3;
		int mid2=r-(r-1)/3;
		if(key==a[mid1])
		 return mid1;
		if(key==a[mid2])
		 return mid2;
		else if(key<a[mid1])
		 return search(a,l,mid1-1,key);
		else if(key>a[mid2])
		 return search(a,mid2+1,r,key);
		else
		 return search(a,mid1+1,mid2-1,key);
	}
	return -1;
}
int main(){
	int s;
	cout<<"Array";
	cin>>s;
	int a[s];
	cout<<"elements";
	for(int i=0;i<s;i++)
	 cin>>a[i];
	int num;
	cout<<"number";
	cin>>num;
	int m=search(a,0,s-1,num);
	if(m==-1)
	 cout<<"not found";
	else
	 cout<<"found at"<<m<<endl;
	return 0;
}*/
/*#include<iostream>
using namespace std;
void adjustheap(int a[],int i,int n){
	int large,temp;
	int l=2*i+1;
	int r=2*i+2;
	large=i;
	if(l<n && a[large]<a[l])
	 large=l;
	if(r<n && a[large]<a[r])
	 large=r;
	if(large!=i){
		temp=a[i];
		a[i]=a[large];
		a[large]=temp;
		adjustheap(a,large,n);
	}
}
void makeheap(int a[],int n){
	for(int i=(n/2)-1;i>=0;i--)
	 adjustheap(a,i,n);
}
void heapsort(int a[],int n){
	makeheap(a,n);
	for(int i=n-1;i>=1;i--){
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		adjustheap(a,0,i);
	}
}
int main(){
	int n,i,a[n];
	cout<<"array";
	cin>>n;
	cout<<"elements";
	for(i=0;i<n;i++)
	 cin>>a[i];
	cout<<"before";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	heapsort(a,n);
	cout<<"after";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
}
*/












