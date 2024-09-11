#include <iostream>
using namespace std;

// class item
// {
//     private:
//         int a,b;
//     public:
//         void setdata(int x,int y)
//         {
//             a=x;
//             b=y;
//         }
//         void showdata()
//         {
//             cout<<"a="<<a<<endl<<"b="<<b<<endl;
//         }
//         friend item operator+(item, item);    //as they are frirend opreatoe overload fun we have to pass calling and modifying obj as a argument 
//         friend item operator+(int, item); 
//         friend item operator-(item);
//         friend void f1(item);
// };
// item operator+(item i1,item i2)          //as they are frirend opreatoe overload fun we have to pass calling and modifying obj as a argument 
// {     
//     item temp;                                // for binary operator 
//     temp.a =i1.a + i2.a;
//     temp.b =i1.b + i2.b;
//     return temp;
// }

// item operator+(int k, item i1)
// {
//     item temp;                                // for binary operator 
//     temp.a =i1.a + k;
//     temp.b =i1.b + k;
//     return temp;
// }

// item operator-(item i)               // as they are not member fun so no need to write membership label
// {
//     item temp;                                //for unary opreator
//     temp.a=-i.a;
//     temp.b=-i.b;
//     return temp;
// }

// void f1(item i)
// {
//     int c=i.a+i.b;
//     cout<<"addition of a and b for an obj is"<<c;
// }

// int main()
// {
//     item i1,i2,i3;

//     i1.setdata(5,6);
//     i2.setdata(79,415);
//     i3.setdata(65,6);

//     i1.showdata();
//     i2.showdata();
//     i3.showdata();
//     i3=i1+i2;        // i3=operator+(i1,i2); 
//     i3.showdata();
//     f1(i3);
//     i3=-i1;          //i3=operator-(i1);
//     i3.showdata();
//     i3=5+i1;           // i3=opereter+(5,i1);
//     i3.showdata();
//     //i3=i1+5;        --->this will give a errror becouse order maters in this
//     cout<<endl;
//     return 0;
// }

// defining << and >> operator over loading 

class item
{
    private:
        int a,b;
    public:
        void setdata(int x,int y)
        {
            a=x;
            b=y;
        }
        void showdata()
        {
            cout<<"a="<<a<<endl<<"b="<<b<<endl;
        }
        friend item operator+(item, item);

        friend ostream& operator<<(ostream&,item&);

        friend istream& operator>>(istream&,item&);    
        //we are giving the referance to istream and ostream in arguments also 
        //due to 
        //cout<<"this is my class"<<"and this is friend fuction"
        //              1st                     2nd 
        //
        //1st string which is exected and the 2nd to concatinate it 1st string 
        //refenace is passed to cout and that cout refeance to 2nd with 1st
/*


In C++, when you overload the >> operator for a class, you typically want to mimic 
the behavior of the standard input stream cin. 
The istream reference (istream&) in the return type allows chaining of input operations.

Consider the expression cin >> item1 >> item2;. This is possible because 
the >> operator of istream returns a reference to the istream object 
itself (istream&). Without this reference return type, chaining wouldn't be 
possible, and you wouldn't be able to write consecutive >> operations like that.

So, when you define friend istream& operator>>(istream&, item&);, 
you're allowing the >> operator to be used in a chain with other >> operations, 
just like with built-in types and cin

same explaination for ostream

*/
};

istream& operator>>(istream& din,item& i)
{   
    din>>i.a>>i.b;
    return din;

}
ostream& operator<<(ostream& dout,item& i)
{
    dout<<i.a<<i.b;  
    return dout;  
}

item operator+(item i1,item i2)          
{     
    item temp;                                
    temp.a =i1.a + i2.a;
    temp.b =i1.b + i2.b;
    return temp;
}
int main()
{
    item i1,i2,i3;
    i1.setdata(5,6);
    i2.setdata(79,415);
    i3.setdata(65,6);
    i1.showdata();
    i2.showdata();
    i3.showdata();
    i3=i1+i2;        
    cout<<endl;

    cin>>i1;       //operator(cin,i1);
    cout<<i1;      //operator(cout,i1);

    return 0;
}