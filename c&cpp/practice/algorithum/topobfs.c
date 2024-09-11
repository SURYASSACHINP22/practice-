#include<stdio.h>

int main()
{
    int flag[10],adj[10][10],queue[10],m=0;
    int i,j,n,k;
    printf("the no of the nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   
        flag[i]=0; 
        queue[i]=0; 
    }

    for(i=0;i<n;i++)
    {   
        for(j=0;j<n;j++)
        {
            printf("nodes no %d%d\n",i,j);
            scanf("%d",&adj[i][j]);
            if(adj[i][j])
            {
                flag[j]++;
            }
        } 
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {   
            if(flag[i]==0)
            {
                flag[i]=-1;
                queue[++m]=i;
                for(j=0;j<n;j++)
                {      
                    if(adj[i][j])
                    {
                        flag[j]--;
                    }
                }
                break; 
            }
        }   
    }
    if(m==n)
    {
        printf("the topological order\n");
        for(i=0;i<n;i++)
        {
            printf("%d",queue[i]);
        }
    }
    else
        printf("the topological order doent exit\n");
}