#include<stdio.h>

void dijkstras(int cost[10][10],int dist[10],int n,int v)
{
    int flag[10],count,min,i,u;
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        dist[i]=cost[v][i];
    }
    flag[v]=1;
    count=1;
    while(count<n)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(dist[i]<min && !flag[i])
            {
                min=dist[i];
                u=i;
            }
        }
        flag[u]=1;
        count++;
        for(i=0;i<n;i++)
        {
            if(dist[u]+cost[u][i]<dist[i] && !flag[i])
            {
                dist[i]=dist[u]+cost[u][i];
            }
        }
    }
}
int main()
{
    int cost[10][10],dist[10],n,v,i,j;
    printf("the no of the nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("nodes no %d%d\n",i,j);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        } 
    }
    printf("the source nodes\n");
    scanf("%d",&v);
    dijkstras(cost,dist,n,v);
    for(i=0;i<n;i++)
    {
        if(i!=v)
        {
            printf("the distance form %d to node %d = %d",v,i,dist[i]);
        }
    }
    return 0;
}
