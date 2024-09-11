#include<stdio.h>

void dfs(int visited[],int vertex,int n,int cost[10][10],int stack[],int *top)
{
    int i;
    visited[vertex]=1;
    for(i=0;i<n;i++)
    {
        if(!visited[i] && cost[vertex][i]==1)
        {   
            dfs(visited,i,n,cost,stack,top);
        }
    }stack[++(*top)]=vertex;
}
void topodfs(int n,int cost[10][10])
{
    int visited[10]={0}, vertex;
    int stack[10],top;
    int i;
    for(i=0;i<n;i++)
    {
        if(!visited[i] && cost[vertex][i]==1)
        {   
            dfs(visited,i,n,cost,stack,&top);
        }
    }
    printf("the topological order is \n");
    while(top!=-1)
    {
        printf("%d",&stack[top--]);
    }
}
int main()
{
    int n,cost[10][10];
    printf("the no of the nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {
            printf("nodes no %d%d\n",i,j);
            scanf("%d",&cost[i][j]);
        } 
    }
    topodfs(n,cost);
    return 0;
}