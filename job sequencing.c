#include<stdio.h>
int j[50],p[50],d[50],k;
int js(int);
int main(){
    int a,temp1,temp2,n,i,j1,sum=0;
    printf("Enter jobs:\n");
    scanf("%d",&n);
    printf("Enter profit datasets:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter deadlines datasets:\n");
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
    printf("Jobs deadlines profit:\n");
    for(i=1;i<=n;i++){
        printf("j[%d]-->%d-->%d\n",i,d[i],p[i]);
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
    printf("profit: %d\n",sum);
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
}
