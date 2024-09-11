#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define max 50

int s[max];
char p[max];
int top=-1;

void push_to_s(int ele);
void calculate(char ele);

void main()
{
    int i;
    printf("enter the postfix expression\n");
    scanf("%s",&p);

    for(i=0;i<strlen(p);i++)
    {
        if(p[i]>='0'&& p[i]<='9')
            push_to_s(i);
        
        if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='%'||p[i]=='^')
            calculate(p[i]);
    }
    printf("the ans is %d",s[top]);
}

void push_to_s(int ele)
{
    s[++top]=(int)(p[ele]-48);
}

void calculate(char ele)
{
    int a,b,ans;

    a=s[top--];
    b=s[top--];

    switch(ele)
    {
        case'+':
                ans=b+a;
                break;
        case'-':
                ans=b-a;
                break;
        case'*':
                ans=b*a;
                break;
        case'/':
                ans=b/a;
                break;
        case'%':
                ans=b%a;
                break;
        case'^':
                ans=pow(b,a);
                break;
        default:ans=0;
    }
    s[++top]=ans;
}