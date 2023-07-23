#include<stdio.h>
void knapsack(int n,float weight[],float profit[],float capacity){
	int i,j;
	float tp=0,x[20];
	int u=capacity;
	for(i=0;i<n;i++)
	 x[i]=0.0;
	for(i=0;i<n;i++){
		if(weight[i]>u)
		 break;
		else{
			x[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
		}
	}
	if(i<=n){
		x[i]=u/weight[i];
		tp=tp+(x[i]*profit[i]);
	}
	printf("\nThe vectors are:\t\n");
	for(i=0;i<n;i++)
	 printf("%.2f\t",x[i]);
	printf("\nThe maximum profit:%.2f\n",tp);
	
}
int main(){
	int i,num,j,temp;
	float w[20],p[20],r[20],capacity;
	printf("Enter no of objects:\n");
	scanf("%d",&num);
	printf("Enter weight and profit:\n");
	for(i=0;i<num;i++)
	 scanf("%f%f",&w[i],&p[i]);
	printf("Enter capacity:\n");
	scanf("%f",&capacity);
	for(i=0;i<num;i++)
	 r[i]=p[i]/w[i];
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(r[i]<r[j]){
				temp=r[j];
				r[j]=r[i];
				r[i]=temp;
				temp=w[j];
				w[j]=w[i];
				w[i]=temp;
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	printf("Profit\t weight\t ratio\n");
	for(i=0;i<num;i++)
	 printf("%.2f\t %.2f\t %.2f\t\n",p[i],w[i],r[i]);
	knapsack(num,w,p,capacity);
	return 0;
	
}



















