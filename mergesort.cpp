#include <iostream>
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
         temp[k]=a[i];
            j++;
            k++;
    }
    for(int p=l;p<=r;p++)
     a[p]=temp[p];
}
void mergesort(int a[],int l,int r,int s){
    if(l<r){
        int m=l+r/2;
        mergesort(a,l,m,s);
        mergesort(a,m+1,r,s);
        merge(a,l,m,r,s);
    }
}
int main()
{
    cout<<"Enter the array size"<<endl;
    int s;
    cin>>s;
    int a[s];
    cout<<"Enter "<<s<<" array elements"<<endl;
    for(int i=0;i<s;i++) 
      cin>>a[i];
     cout<<"Before sorting:"<<endl;
     for(int i=0;i<s;i++) 
      cout<<a[i]<<" ";
     cout<<endl;
     mergesort(a,0,s-1,s);
     cout<<"After sorting:"<<endl;
     for(int i=0;i<s;i++) 
      cout<<a[i];
    return 0;
}
