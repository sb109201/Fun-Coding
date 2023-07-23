#include<stdio.h>
int p[50],d[50];
int j[50],k;
int js(int);
int main()
{
	int n,i,a,j1,temp1,temp2,sum=0;
	int id[5],t;
	printf("Enter the no. of jobs:");
	scanf("%d",&n);
	printf("Enter the profit dataset:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter the deadline dataset:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	//Bubble sorting
	for(i=1;i<=n;i++)
	{
		for(j1=1;j1<=n-i;j1++)
		{
			if(p[j1]<p[j1+1])
			{
				temp1=p[j1];
				p[j1]=p[j1+1];
				p[j1+1]=temp1;

				temp2=d[j1];
				d[j1]=d[j1+1];
				d[j1+1]=temp2;
			}
		}
	}
	printf("Job Deadline Profit\n");
	for(i = 1; i<=n; i++) {
		printf(" j[%d] %d %d\n",i ,d[i],p[i]);
	}
	a=js(n);
	printf("The no. of available job is:%d\n",a);
	printf("The job in sequence are:-");
	for(i=1;i<=k;i++)
	{
		printf("%d--->",j[i]);
	}
	printf("Null");
	printf("\n");
	for(i=1;i<=k;i++)
	{
		sum+=p[i];
	}
	printf("profit:%d",sum);
	return 0;
}

int js(int n)
{
	int i,r,q;
	d[0]=j[0]=0;

	j[1]=1;
	k=1;
	for(i=2;i<=n;i++)
	{
		r=k;
		while((d[j[r]]>d[i]) && (d[j[r]]!=r)) {
			r=r-1;
		}
		if((d[j[r]]<=d[i]) && (d[i]>r)) {
			for(q=k;q>=(r+1);q--)
			{
				j[q+1]=j[q];
			}
			j[r+=1]=i;
			k=k+1;
		}
	}
	return k;
}
