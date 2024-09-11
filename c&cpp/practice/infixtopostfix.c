#include<stdio.h>
#include<ctype.h>

#define size 50
char s[size];
int top=-1;

void push(char ele)
{
    s[++top]=ele;
}

char pop()
{
    return (s[top--]);
}

int pr(char ele)
{
    switch(ele)
    {
        case'#': return 0;
        case'(': return 1;
        case'+': 
        case'-': return 2;
        case'*':
        case'/': 
        case'%': return 3;
        case'^': return 4;
    }
}
void main()
{
    char infx[50],pofx[50],ele,ch;
    int i=0,k=0;
    printf("enter the infix expression \n");
    scanf("%s",&infx);

    push('#');
    while((ch=infx[i++])!='\0')
    {
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))
            pofx[k++]=ch;
        else if(ch==')')
            {
                while(s[top]!='(')
                    pofx[k++]=pop();
                ele=pop();
            }
        else
        {
            while(pr(s[top])>=pr(ch))
                pofx[k++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#')
    {
        pofx[k++]=pop();
    }
    pofx[k]='\0';
    printf("the post fix expression is %s",pofx);
}