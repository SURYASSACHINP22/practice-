#include<iostream>
#include<string.h>
using namespace std;

int fibo(int n)
{
    if(n==1||n==2)
    {
        return 1;
    }
    return fibo(n-1)+fibo(n-2);
}

// namespace forn1
// {
//     int a=10;
// }

// cin and cout are the obj of i and ostream class which are declered in
// namespace std due to avoidance of nameconflict

/*
referance variable shoude be assigned when they created and variable can
only assigned not any constant referance variable cant modified after the
assigment
            pointer                     reference

            int *ptr;                   int &ptr=x;
            ptr=&x;
*/
inline int squre(int x);
//inline not work on loop,reccursion,goto,switch and static variable

// you can write class insted of struct and visa versa both are same
struct book
{
    public:

    int bookid;
    char title[20];
    float price;

    inline void displaybook_struct();
    //you can make fun inside the sturct in cpp but not in c 
    // and also give the access  specifier in struct like public 
};

void book::displaybook_struct()
{
    cout<<this->bookid<<"\n"<<title<<"\n"<<price;
}

struct book input_book();
inline void displaybook(struct book);

int main()
{
     //both book and sturct book is same 
    book b4;                                  
    struct book b1={1,"my c++ ",1000},b2,b3;
    // in c we can use tydedef but in c++ no need to do typedef

    b2.bookid=2;
    //b2.title="hello world";     
    // in the above command this is string so in this pointer is assighned to contsant which is ERROR
    strcpy(b2.title,"hello world");  
    b2.price=2814.5;

    b3=input_book();
    b4=input_book();
    
    displaybook(b3);
    b1.displaybook_struct();
    cout<<endl;
    displaybook(b2);
    displaybook(b4);

    // int n;
    // cout<<"enter upto what value of terms you want\n";
    // cin>>n;
    //cout<<fibo(n);
    //cout<<forn1::a;
    // int x,y;
    // printf("enter the value of the x to find the squre of the no\n");
    // cin>>x;
    //y=squre(x);
    //cout<<"the squre of the no is"<<x<<"is "<<y;
}
struct book input_book()
{
    struct book b;
    cout<<"enter the  id and name and price  of the book resp..\n";
    cin>>b.bookid;
    // fflush(stdin);
    // fgets(b.title,20,stdin);
    // you can also use cin.ignore and cin.getline also which are given by c++ both are same
    cin.ignore();
    cin.getline(b.title,20);
    cin>>b.price;
    return b;
}
void displaybook(struct book book)
{
    cout<<book.bookid<<"\t"<<book.title<<"\t"<<book.price;
    cout<<endl;
}

int squre(int x) 
{
    return x*x;
}