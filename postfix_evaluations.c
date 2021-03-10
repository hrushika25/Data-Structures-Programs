#include<stdio.h>
#include<ctype.h>
#define SIZE 30

int s[SIZE],op1,op2,top=-1,item,n,i=0,res;
char postfix[SIZE],ch;
int pop()
{
    item = s[top--];
    return item;
}
void push(int n)
{
    s[++top]=n;
}
int main()
{   printf("Enter the postix expression:");
    gets(postfix);
    while(postfix[i] != '\0')
    {
        ch=postfix[i];
        if(isalpha(ch))
        {
            printf("enter value for %c ",ch);
            scanf("%d",&n);
            push(n);
        }
        else
        {
        op2=pop();
        op1=pop();
        switch(ch)
        {
            case '+':res=op1+op2;
                    push(res);
                    break;
            case '-':res=op1-op2;
                    push(res);
                    break;
            case '*':res=op1*op2;
                    push(res);
                    break;
            case '/':res=op1/op2;
                    push(res);
                    break;
            case '^':res=op1^op2;
                    push(res);
                    break;
            default:printf("errrorr");
                    break;
        }
        }
        i++;
    }
    res=s[top];
    printf("the result is %d",res);
    return 0;
}
