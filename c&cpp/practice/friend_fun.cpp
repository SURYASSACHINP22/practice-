#include <iostream>
using namespace std;

// friend fuction can be creted using friend keyword and it can 
// only acess the member fuction of class to which it is friend
// not can modify the data to it directly 
// indirectly we can do
// friend function can be have friend to many class


class A{
    public:

    void member_of_class_A();

};
void A::member_of_class_A()
{
    cout<<"hello i am member function of class a and friend of item\n";
}


class item{
    private:
        int a,b;
    public:

        friend void f1();                  
        //friend fun to this class is not menmber to another class
    
        void setdata(int x,int y):a(x),b(y)
        {}
        friend void f2(itam);
        //passing args to the friend fution to modify or manupulate the data
        // you need to pass obj and return that obj


        friend void A::member_of_class_A();
        //this fuction is member of another class 
        //then you have to write the membership to use this function as a friend to this clsss

};
void f1()                // passing no argments to this fuction
{
    cout<<"hello";
}
void f2(item i)
{
    int c=i.a+i.b;
    cout<<"sum is "<<c<<endl;
}

//void A::member_of_class_A();
// altho this function is declerd any where you dont need to write again
//if you want to change this fuction then simply override this fuction

// no need to declear this friend fun outside of this class 
// becouse it is not a membr of this class only it is friend funtion 
// to this class only the declearation is dine for member
// function and static variable  only not for friend fuction


int main()
{
    f1();                // we can call this function which is friend to class
    cout<<endl;          // directly becouse it is not a member fuction to class so
                         // only memebr var and instance var and fuction resp
                         // need to call by using the obj of class
    item i1;
    i1.setdata(5,6);
    f2(i1);                 // passing the arg to friend fuction of same class obj
    cout<<endl;


}








/*
class complex
{
    private:
        int real,imag;

    public:

    complex(int x,int y)
    {
        real=x;
        imag=y;
    } 

    inline void set(int ,int);   
    inline void show();

    complex operator+(complex); 

    complex operator-(complex c);
};

void complex::set(int r,int i)
{
    real=r;
    imag=i;
} 

void complex::show()
{
    cout<<"the complex no is== "<<real<<"+"<<imag<<endl;
}

complex complex::operator+(complex c)
{
    complex temp(0,0);
    temp.real=real+c.real;
    temp.imag=imag+c.imag;
    return temp;
}

complex complex::operator-(complex c)
{
    complex temp(0,0);
    temp.real=c.real-1;
    temp.imag=c.imag-1;                  
    return temp;                           
}
int main()
{  
    complex c1(18,51),c2(45,19),c3(51,66);  
    c1.show();
    c2.show();
    c3.show();
    c3=c1.operator+(c2);    
    c3.show();                       
    cout<<endl<<endl;
}
*/
