#include <iostream>
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
void quicksort(int a[],int s,int e){
    if(s<e){
        int p=partition(a,s,e);
        quicksort(a,s,p-1);
        quicksort(a,p+1,e);
    }
}
int main()
{
    int s=0;
    cout<<"Enter array size :"<<endl;
    cin>>s;
    int a[s];
    cout<<"Enter "<<s<<" elements:"<<endl;
    for(int i=0;i<s;i++)
    cin>>a[i];
    cout<<"Before sorting:"<<endl;
    for(int i=0;i<s;i++)
    cout<<a[i]<<" ";
    quicksort(a,0,s-1);
    cout<<endl;
    cout<<"After sorting:"<<endl;
    for(int i=0;i<s;i++)
    cout<<a[i]<<" ";
    return 0;
}

