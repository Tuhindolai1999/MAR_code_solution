#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct
{
    char a[max];
    int top;
}stk;
void create(stk *p)
{
    p->top=-1;
}
void push(stk *p,char opr)
{
    if(p->top>=max-1)
       return;
    else
    {
        p->a[++p->top]=opr;
        //return 1;
    }

}
char pop(stk *p)
{
    char opr;
    if(p->top==-1)
        return '0';
    else
    {
        opr=p->a[p->top--];
        return opr;
    }
}
char operator1(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        return x;
    else
        return 0;
}
int precedence(char x)
{
    switch(x)
    {
        case '(':
            return 0;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
    }
}
char in_to_post(char *a,stk *p)
{
    char b[max];
    int i=0,k=0;
    while(a[i]!='\0')
    {
        if(a[i]=='(')
        {
            push(p,a[i]);

        }

        else if(a[i]==operator1(a[i]) )

        {
           if(p->top==-1)
        {
            push(p,a[i]);
        }
              else if(precedence(a[i])<=precedence(p->a[p->top]))
            {
            {
                while(precedence(a[i])<=precedence(p->a[p->top]))
                {
                   b[k++]=pop(p);
                }
            }
            push(p,a[i]);
            }
            else
            {
                push(p,a[i]);
            }
        }


        else if(a[i]==')')
        {
            while(p->a[p->top]!='(')
            {
                b[k++]=pop(p);

            }
            pop(p);
        }
        else
        {
            b[k++]=a[i];
            //b[k++]=pop(p);
        }
        i++;
    }
    while(p->top!=-1)
    {
        b[k++]=pop(p);
    }
    b[k]='\0';
    //printf("After convert:\n");
    //puts(b);
    return *b;
}
int main()
{
    stk s;
    char ip[max],*op;
    int i;
    create(&s);
    printf("Enter the infix Expression:\n\n");
    fflush(stdin);
    gets(ip);
    op=in_to_post(ip,&s);
    printf("After convert:\n\n");
   /* for(i=0;op[i]!='\0';i++)
    {
        printf("%c",*(op+i));
    }*/
    puts(op);
    return 0;
}


