#include<stdio.h>
int x[30],w[30],d,b=1;
void sumofset(int s,int k,int r)
{
    int i;
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("the solution is %d",b++);
        for(i=0;i<k;i++)
        {   
            if(x[i]==1)
            {
                printf("%d",w[i]);
            }
        }
    }
    else if(s+w[k]+w[k+1]<=d)
        sumofset(s+w[k],k+1,r-w[k]);
    if(s+r-w[k]>=d && s+w[k+1]<d)
    {
        x[k]=0;
        sumofset(s,k+1,r-w[k]);
    }
}
int main()
{
    int i,sum=0,n;
    printf("enter the no of element in set\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("the set item = %d",i);
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    printf("enter the max sum you want\n");
    scanf("%d",&d);
    sumofset(0,0,sum);
}