#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int low,int mid,int high);

void merge_sort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i,j,b[10000],k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;i++;
        }
        else
        {
            b[k]=a[j];
            k++;j++; 
        }
    }
    while(i<mid)
    {
        b[k]=a[i];
        k++;i++;  
    }
    while(j<high)
    {
        b[k]=a[i];
        k++;j++;  
    }
    for(i=low;i<high;i++)
    {
        a[i]=b[i];
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
        merge_sort(a,0,n);
        t_end=clock();
        total_time=(double)((t_end - t_start)/CLOCKS_PER_SEC);
        fprintf(fp,"%d \t %f \n",n,total_time);
        printf("for n=%d  the total time=%f \n",n,total_time);
        n=n+500;
    }
    fclose(fp);
    return 0;
}