#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}

void knapsack(int w,int wt[],int val[],int n)
{
    int i,j;
    int table[10][10];
    for(i=0;i<n;i++)
    {
        for(j=0;j<w;j++)
        {
            if(i==0||j==0)
                table[i][j]=0;
            else if(wt[i-1]<=j)
            {
                table[i][j]=max(val[i-1]+table[i-1][j-wt[i-1]],table[i-1][j]);
            }
            else
                table[i][j]=table[i-1][j];
        }
        printf("the maximaum profit is %d",table[n][w]);
    }
}

int main()
{
    int w,wt[10],val[10],n;
    printf("the no of the element in knapsack\n");
    scanf("%d",&n);
    printf("the weight and profit for the each item\n");
    for(int i=0;i<n;i++)
    {
        printf("the weight for item %d",n);
        scanf("%d",&wt[i]);
        printf("the profit for item %d",n);
        scanf("%d",&val[i]);
    }
    printf("the max capacity for knapsak");
    scanf("%d",&w);
    knapsack(w,wt,val,n);
    return 0;
}
