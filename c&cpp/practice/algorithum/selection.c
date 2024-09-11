#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection(int a[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
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
        selection(a,n);
        t_end=clock();
        total_time=(double)((t_end - t_start)/CLOCKS_PER_SEC);
        fprintf(fp,"%d \t %f \n",n,total_time);
        printf("for n=%d  the total time=%f \n",n,total_time);
        n=n+500;
    }
    fclose(fp);
    return 0;
}