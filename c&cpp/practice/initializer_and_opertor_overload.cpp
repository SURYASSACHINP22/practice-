#include <iostream>
using namespace std;

class abhi_na_jao_chodke{
    private: 
        int a,b,c;
        const int k;
        const int &x;
        //const int &x=k;    both are correct 
    public:
        abhi_na_jao_chodke():a(5), b(6), c(5), k(6), x(k) {}

        abhi_na_jao_chodke(int a,int b,int c):a(a), b(b), c(c), k(6), x(k)
        {}
        abhi_na_jao_chodke(int x):k(6),x(k)
        {}

        // abhi_na_jao_chodke(int x):k(6)   // this is not correct 
        // {                                   insted of this you can 
        //     x=k;                             initilize
        // }                                it in private sec like this 
        //                                  const int *x=k;                                  
        //
        //to initialize a const variable to referance variable
        //you need a 
        //constant int &x    ----> this is a correct 
        //int &x    ---> this will give a error
/*


abhi_na_jao_chodke()
{
    k=10;
}

it is wrong type of initializaion to const variable it will throw a ERROR
you need to initialize with a initializer only 

initializer are used to initializ the constructor 
const variable , and referace variable and data memders of fun

it is also used for the invoke the base class constuctor


abhi_na_jao_chodke():k(6),x(k)
        {}
         in this x(k)===>> x(*new int);


*/

    void display() {
        cout << "a: " << a << ", b: " << b << ", c: " << c << ", k: " << k << ", x: " << x << endl;
    }

};
int main()
{
    // Create objects and display their values
    abhi_na_jao_chodke obj1;
    obj1.display();

    abhi_na_jao_chodke obj2(1, 2, 3);
    obj2.display();

    abhi_na_jao_chodke obj3(10);
    obj3.display();

    return 0;
}