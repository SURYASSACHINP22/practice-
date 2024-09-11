#include<iostream>
using namespace std;

int fact(int x);
int ncr(int n,int r);

int main()
{
    int n;
    cout<<"enter the value of the n ";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
       cout<<fact(i);
       cout<<endl;
    }
    cout<<endl;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<ncr(i,j)<<" ";
        }
        cout<<endl;
    }
}
int fact(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
        return n*fact(n-1);
}

int ncr(int n,int r)
{
    int a=fact(n);
    int b=fact(r);
    int c=fact(n-r);
    return a/(b*c);
}
