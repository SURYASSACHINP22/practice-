#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partion(int a[],int low,int high)
{
    int key,i,j;
    key=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(i<high && key>a[i])
            i++;
        while(j>low && key<a[j])
            j--;
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            int temp=a[j];
            a[j]=a[low];
            a[low]=temp;
            return j;
        }
    }
}

void quick(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partion(a,low,high);
        quick(a,low,j-1);
        quick(a,j+1,high);
    }
   
}
int main()
{
    int a[10000],n=1000,i;
    double total_time=0.0;
    clock_t t_start,t_end;
    FILE *fp;
    fp=fopen("selection.txt","w");
    srand(time(NULL));
    for(int j=0;j<10;j++)
    {
        printf(" for n = %d",n);
        for(i=0;i<n;i++)
        {
            a[i]=rand()%10000;
        }
        t_start=clock();
        quick(a,0,n);
        t_end=clock();
        total_time=(double)(t_end - t_start)/CLOCKS_PER_SEC;
        fprintf(fp,"%d \t %f \n",n,total_time);
        printf("for n=%d  the total time=%f \n",n,total_time);
        n=n+500;
    }
    fclose(fp);
    return 0;
}