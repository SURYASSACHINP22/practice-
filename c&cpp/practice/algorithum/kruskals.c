#include<stdio.h>

int main()
{
    int parent[10],min,mincost=0,ne=1,adj[10][10];
    int i,j,a,b,u,v,n;
    printf("the no of the nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   
        parent[i]=0;
        for(j=0;j<n;j++)
        {
            printf("nodes no %d%d\n",i,j);
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0)
            {
                adj[i][j]=999;
            }
        } 
    }
    while(ne<n)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(adj[i][j]<=min && !parent[i])
                {
                    min=adj[i][j];
                    a=u=i;
                    b=v=j;
                }
            } 
        }
        while(parent[u]!=0)
            u=parent[u];
        while(parent[v]!=0)
            v=parent[v];
        if(u!=v)
        {
            printf("the node with edge(%d,%d)--->%d",u,v,u,min);
            mincost+=min;
            parent[v]=u;
        }
        adj[a][b]=adj[b][a]=999;
    }
    printf("the mincost %d",mincost);
    return 0;
}