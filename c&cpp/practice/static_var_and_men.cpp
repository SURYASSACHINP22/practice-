#include<iostream>
#include<string.h>
using namespace std;
/*


static variable get memory in  once time and also it can be modified by class only
not by the obj of class although the variable can be acess by both obj and class but 
static var is created only once so different obj of class same class give the same result
and obj also cant modify its value 


class item
{
    public:
        int a,b;
        static int k;       -----> for static var is created hare using static keyword
                                only this will give the error if you didnt write the membership
};

int item::k;        -------> it is manditory to write the membership for static var
                        so that only writeing this the variable get the memeroy and 
                        programe var other content get know 

int main()
{  
    item i1;
    item::k=10;
    cout<<"for class k= "<< item::k++;   ---> only class can modify the value of static var
    cout<<endl;
    cout<<"for obj k= "<< i1.k++;       ----> this will not incremet the value of static var
    return 0;
}





//  case 1---> when private static variable and obj is crated for a class then we can use obj only





class item{
    private:
        int a,b;
        static int k;
    public:
        void nonstatic(int x,int y)
        {
            a=x;
            b=y;
        }
        void staticfun(int z)   //it should be static for accesing throug class 
        {   
            k=z;
        }
        int* getAandB()
        {
            static int arr[2];  //due to local array which will destory after fun completed and
            arr[0]=a;           // so to retuen the value of the arry we maked it static 
            arr[1]=b;           // this also can be done by using dynamic array
            return arr;         //  int *arr = new int[2];
        }
        int getk()       //to acess this fun by class name  you have to do it static
        {                   //after this you can acess it using obj and class also
            return k;
        }
};
int item::k;

int main()
{
    item i1,i2;
    i1.nonstatic(4,5);
    int *arr;
    arr=i1.getAandB();
    for(int i=0;i<2;i++)
        cout<<arr[i]<<endl;
    i1.staticfun(6);
    cout<<"\n";
    cout<<" with i1 obj k="<<i1.getk();
    cout<<"\n";
    cout<<" with i2 obj k="<<i2.getk();
    cout<<"\n";

    cout<<" with item class obj k="<<item::getk();      you can not acess using class name need obj  
                                                        to acess it using class name you need to
                                                        do the get fuction also static

    cout<<" direct with item class (without fuction)k="<<item::k;
    
    you can not acess the private k satic form outside of class whic is wrong
    you can acess it usig class :: and obj. with member fuction only

}
*/

//case 2----> when obj is not created then mAke use of static method 
//to initialize private static variable

class item
{
    private:
        static int k;

    public:

    static void staticfun(int z)   
    {   
        k=z;
    }
    static int getk()       
    {                  
        return k;
    }
};

int item::k;                      //it is mandetory to write for static var for acessing and memory initilization for it
//void item::staticfun(int z);       the static fun decleartion not memdetory to wirte 
//int item::getk();                but its a good practices you should write

int main()
{  
    item i1;
    item::staticfun(10);
    cout<<" with item class obj k="<<item::getk()<<endl;
    cout<<"for obj k= "<< i1.getk();       
    return 0;
}