#include<iostream>
using namespace std;

class pattern
{
    private:
    int row ;

    public:

    inline void triangle (int m)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
         } 
    }
    void invert_tri(int m, int n);
    void plus_sign(int n);

};
void pattern::invert_tri(int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n+1-i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern::plus_sign(int n)
{ 
    int mid=(n/2)+1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==mid || i==mid)
            {
                cout<<"* ";
            }
            cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int m,n;
    cout<<"enter the value of m and n \n"<<endl;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;

    pattern p1;
    p1.invert_tri(3,3);
    cout<<endl;

    p1.triangle(3);
    cout<<endl;
    
    p1.plus_sign(6);
    cout<<endl;
}
