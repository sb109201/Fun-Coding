#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int generaterandompivot(int low,int high){
    srand(time(NULL));
    return low +rand()% (high-low+1);
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int pi=generaterandompivot(low,high);
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
        quicksort(a,low,i);
        quicksort(a,i+2,high);
    }
}
int main(){
    int n;
    cout<<"Enter array size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++)
     cin>>a[i];
    cout<<"Before sorting :"<<endl;
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
    cout<<endl;
    quicksort(a,0,n-1);
    cout<<"After sorting :"<<endl;
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
     return 0;
}
