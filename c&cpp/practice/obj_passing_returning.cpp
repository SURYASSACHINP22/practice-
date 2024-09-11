#include<iostream>
using namespace std;

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
    complex(complex &c)      //copy constuctor our own
    {
        real=c.real;
        imag=c.imag;
    }
/*
when you cant creat any constructor then compilor make 2 constructor
which r default and copy constructor

when you crate a own constuctor the compiler make only copy constructor
it wont make a default contructor 

complex (complex c)
{

}
this is wrong due it occure a reccurive obj creation
not initialization of a complex obj to complex class 
so 
to overcome this issue we can use the referance so 
that it will not crate any obj when obj is passed to class 

complex(complex &c)
{

}

copy constuctor is used to deep copy of obj which will not chang 
when the main obj valve is changed

{
    a=obj.a;
    p=malloc(4);    you can use new insed of malloc
    *p=*(obj.p);
}


*/
    inline void set(int ,int);   
    inline void show();
    complex add(complex);
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
complex complex::add(complex c)
{
    complex temp(0,0);
    temp.real=real+c.real;
    temp.imag=imag+c.imag;
    return temp;
}

int main()
{  
    complex c1(18,51),c2(45,19),c3(51,66);  //using constructor 
    c1.show();
    c2.show();
    c3.show();
    c3=c1.add(c2);
    c3.show(); 

    cout<<endl<<endl;   //now using fuction

    c1.set(3,5);
    c1.show();
    c2.set(8,9);
    c2.show();
    c3.set(0,0);
    c3.show();
    c3=c1.add(c2);  
    c3.show();     
    return 0;

    cout<<endl<<endl;

    complex c5(c1);
    c5.show();

    cout<<endl<<endl;

    complex c4=c1;   // it is possiable due to copy constructor
                    // it is correct way syntax to write
    c4.show();  //initialize a copy constor when u creat a copy constructor 

 // complex c4;
 // c4 = c1;     it is wrong way to initialize a copy contuctor

}







/*
In C++, a move constructor is a special constructor that 
allows the resources owned by an rvalue reference 
(such as temporary objects) to be moved rather than copied. 
It is invoked when an rvalue reference is used to initialize an
 object, typically during move operations like returning objects
  from functions or using them in expressions.

The move constructor signature typically looks like this:

cpp
Copy code

complex(complex &&c) // Move constructor

Here, && denotes an rvalue reference, which binds to 
temporary objects or objects that are about to be moved.

Since you didn't define a move constructor explicitly
 in your code, the compiler doesn't provide it as an option 
 when initializing a complex object. If you want to enable move 
 semantics for your complex class, you can define a move constructor 
 similar to how you defined the copy constructor, but with an rvalue 
 reference parameter.



#include <iostream>

using namespace std; // Import the entire std namespace

class complex {
private:
    int real, imag;

public:
    // Constructor with parameters
    complex(int x, int y) : real(x), imag(y) {}

    // Copy constructor
    complex(const complex &c) : real(c.real), imag(c.imag) {}

    // Move constructor
    complex(complex &&c) noexcept : real(c.real), imag(c.imag) {
        c.real = 0;  // Reset the moved object
        c.imag = 0;
    }

    // Member function to display complex number
    void show() {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

int main() {
    complex c1(10, 20);
    complex c2(std::move(c1));  // Using move constructor

    cout << "After moving c1 to c2:" << endl;
    cout << "c1: ";
    c1.show();  // c1 has been moved, so it's in an unspecified state
    cout << "c2: ";
    c2.show();  // c2 holds the values previously in c1

    return 0;
}

In the move constructor `complex(complex &&c)`, the `noexcept` specifier 
indicates that the function doesn't throw any exceptions.

Regarding the resetting of the moved object `c`, it's not 
typically done in a move constructor. The purpose of a move 
constructor is to efficiently transfer the resources owned by the 
source object to the destination object. After the move operation,
 the source object should be in a valid but unspecified state, 
 meaning you shouldn't rely on its state after it has been moved from.

However, it's perfectly valid to reset the moved-from object's state
 if that's the behavior you desire. Just keep in mind that it's not a 
 common practice and might be unexpected for users of your class. 
 Here's the relevant part of your move constructor with the reset 
 0peration:

```cpp
// Move constructor

complex(complex &&c) noexcept : real(c.real), imag(c.imag) {
    c.real = 0;  // Reset the moved object
    c.imag = 0;
}
```

This code sets the real and imaginary parts of the 
moved-from object `c` to 0 
after the move operation.

*/