#include<iostream>
using namespace std;
class pattern2
{
    public:
    void opptri(int m,int n);
};
void pattern2::opptri(int m,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            cout<<"* ";
        }
        for(int j=1;j<i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n;
    cout<<"enter the value of m and n \n"<<endl;
    cin>>m>>n;
    pattern2 op1;
    op1.opptri(m, n); 
}