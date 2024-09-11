#include<stdio.h>
#include<math.h>

int x[30],count=1;

int place(int k,int j)
{
    int i;
    for(i=0;i<k;i++)
    {
        if(x[i]==j || abs(x[i]-x[j])==abs(i-k))
            return 0;
    }
    return 1;
}

void nqueen(int k,int n)
{
    int i,j;
    for(j=0;j<n;j++)
    {
        if(place(k,j))
        {
            x[k]=j;
            if(k==n-1)
            {   
                printf("the solution no %d",count);
                count++;
                for(i=0;i<n;i++)
                {
                    printf("the queen in row %d and in colum %d",i+1,x[i]+1);
                }
            }
            else
            {
                nqueen(k+1,n);
            }
        }
    }
}
int main()
{
    int n;
    printf("enter the no of queen\n");
    scanf("%d",&n);
    nqueen(1,n);
    return 0;
}