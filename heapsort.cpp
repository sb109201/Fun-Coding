#include<iostream>
using namespace std;
void adjustheap(int a[],int i,int n){
	int temp,large;
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
	for(int i=(n/2)-1;i>=0;i--)
	 adjustheap(a,i,n);
}
void heapsort(int a[],int n){
	makeheap(a,n);
	int i,temp;
	for(i=n-1;i>=1;i--){
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		adjustheap(a,0,i);
		
	}
}
int main()
{
    int s;
    cout<<"Enter array size :"<<endl;
    cin>>s;
    int a[s];
    cout<<"Enter "<<s<<" elements:"<<endl;
    for(int i=0;i<s;i++)
    cin>>a[i];
    cout<<"Before sorting:"<<endl;
    for(int i=0;i<s;i++)
    cout<<a[i]<<" ";
    heapsort(a,s);
    cout<<endl;
    cout<<"After sorting:"<<endl;
    for(int i=0;i<s;i++)
    cout<<a[i]<<" ";
    return 0;
}






