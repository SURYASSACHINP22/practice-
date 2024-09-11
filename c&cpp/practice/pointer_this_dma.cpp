#include<iostream>
using namespace std;

class item{
    private:
        int a,b;
    public:
        void setdata(int a,int b){
            //this is pointer when mem variable and arguments have same name 
            //this.a=a;   this will give error due it is poiner although
            // we can write in java but it is wrong in cpp insted of this 
            //we can write   this->a    or  (*this).a;
            (*this).b=b;
            this->a=a;
        }
        void showdata()
        {
            cout<<"a="<<this->a<<" b="<<(*this).b;
        }
        item greater(item obj);
};
item item::greater(item obj)
{
    if(a+b > obj.a+obj.b)
        return *this;        // only writing this its give the adress of the obj
    else                        // so we can write *this is returns obj
        return obj;
}
int main()
{
    item i1,i2,i3;
    i1.setdata(10,20);
    i1.showdata();
    cout<<endl;
    
   class item *a =new class item();    
   item *a1=new item();
   class item* a3= new item();
   item* a5=new class item();

// all these above 4 are correct you can write any one form also

// int* p= new int();     this is for int type

//this is dyanamic type of allocation same in 
//same like java 
// in java     father f1= new child(); 

    a->setdata(9,10);
    a->showdata();

    a1->setdata(9616,10);
    a1->showdata();

    a3->setdata(9168,10);
    a3->showdata();

    i3=i1.greater(i2);
    cout<<endl;
    return 0;
}


//dyanamic memory allocation
// "   new   "---> this is used insted of malloc and calloc and realloc
//
// sturct node *NODE=(struct node*)malloc(sizeof(struct node))
//
// this above can be written by using new 
//
// struct node *NODE= new sturct node;

// insted of free we can use delete function 