#include <iostream>
using namespace std;
/*


class abhi_na_jao_chodke{
    private:
        const int k;
        const int *x;
        //const int &x=k; 
    public:

        abhi_na_jao_chodke():k(6),x(k)
        {}

        void display() {
        cout <<"k: " << k << ", x: " << x << endl;
    }
};

int main()
{
    // Create objects and display their values
    abhi_na_jao_chodke obj1;
    obj1.display();
    return 0;
}


*/


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

    complex(complex &c)    //this is a copy constuctor 
    {
        real=c.real;
        imag=c.imag;
    } 

    inline void set(int ,int);   
    inline void show();

    complex operator+(complex);       //opreator overloading
    
    complex operator-();               // this is for normal operator overloda fun
    //complex operator-(complex c);       // this is for friend operator over fun syntax correct for unary friend oprator overloading
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
complex complex::operator-()
{
    complex temp(0,0);
    temp.real=real-1;
    temp.imag=imag-1;
    return temp;
}

// complex complex::operator-(complex c)
// {
//     complex temp(0,0);
//     temp.real=c.real-1;                   this type of syntax we have to 
//     temp.imag=c.imag-1;                   write when we make a friend function opreator overlodoing in class we have pass atlest one arg to initilize it
//     return temp;                           
// }

int main()
{  
    complex c1(18,51),c2(45,19),c3(51,66);  
    c1.show();
    c2.show();
    c3.show();

    c3=c1.operator+(c2);     //this both are same you can write any one of them
    c3.show();                       
    c3=c1+c2;              //but this is best to use 

    c3.show(); 
    cout<<endl<<endl; 

    c1.set(3,5);
    c1.show();
    c2.set(8,9);
    c2.show();
    c3.set(0,0);
    c3.show(); 

    c3=c1.operator+(c2);  
    c3.show();  

    cout<<endl<<endl;

    complex c5(c1);
    cout<<"this is for complex c5(c1)";
    c5.show();

    cout<<"this is for complex c4=c1";
    complex c4=c1;   
    c4.show();

    cout<<endl<<endl;

                           // for unary oprator overloaing
    c3=c1.operator-();     //this syntax for normal operator verloding funtion
    cout<<"this is for c3=c1.operator-()";
    c3.show(); 
    cout<<"this is for c3=-c1";
    c3=-c1;               // this is also correct for normal operator over fun
    c3.show();

    //c3=c1-;       // this will give ERROR for unary oprator overloaing

    //c3=operator-(c1);     this is used to initialize friend oprector overloding fuction of class 
    //c3=-c1;
}
