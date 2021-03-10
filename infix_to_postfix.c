#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 30
char infix[SIZE],postfix[SIZE],s[SIZE],ch,temp;
int top=-1,i=0,j=0;
void push(char ch)
{
    s[++top] = ch;
}
char pop()
{   char temp;
    temp = s[top--];
    return temp;
}
int precedence(char ch)
{
   switch(ch)
   {
        case '^':return 5;
                break;
        case '/':case '*':return 4;
                break;
        case '+':case '-':return 3;
                break;
        case '%':return 2;
                break;
        default: return 1;
                break;
   } 
}
int isoperator()
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%')
        return 1;
    else
        return 0;
}
int main()
{
    printf("Enter infix expression: ");
    gets(infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalpha(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else if(isoperator(ch)==1)
        {
            if(ch != '^')
            {
                while(precedence(ch) <= precedence(s[top]))
                {
                    postfix[j]=pop();
                    j++;
                }
                
            }
            push(ch);
        }
        else if(ch ==')')
        {
            while(s[top] != '(')
            {
                postfix[j]=pop();
                j++;
            }
            temp=pop();

        }
        else
           printf("  Wrong input  ");
        i++;
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    printf("\nthe postfix expression is:  ");
    for(j=0;postfix[j]!='\0';j++)
    {
        printf("%c ",postfix[j]);
    }

    return 0;
}
