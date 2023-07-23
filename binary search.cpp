#include<iostream>
using namespace std;
int bs(int a[],int num,int beg,int end){
	int mid;
	if(beg>end){
	cout<<"Number is not found"<<endl;
	return 0;
	}
	else{
		mid=(beg+end)/2;
		if(a[mid]==num){
		 cout<<"Number is found at "<<mid<<" index";
		 return 0;
	    }
	    else if(num<a[mid]){
	    	bs(a,num,beg,mid-1);
		}
		else if(num>a[mid]){
			bs(a,num,mid+1,end);
		}
	}
}
int main(){
	int s;
	cout<<"Enter array size:"<<endl;
	cin>>s;
	int a[s];
	cout<<"Enter elements :"<<endl;
	for(int i=0;i<s;i++)
	 cin>>a[i];
	int num;
	cout<<"Enter number to found :"<<endl;
	cin>>num;
	int beg=0,end=s-1;
	bs(a,num,beg,end);
	return 0;
}











