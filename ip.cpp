#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char istack[20];
int tos=-1;
float stack[20];
int top=-1;
void ipush(char s)
{
    istack[++tos]=s;
}
char ipop()
{
    return (istack[tos--]);
}
int precd(char s)
{
    switch(s)
    {
        case '^':return 4;
        case '*':
        case '%':
        case '/':return 3;
        case '+':
        case '-':return 2;
        case '(':
        case ')':
        case '#':return 1;
    }
    return 0;
}
void convertip(char infix[20],char postfix[20])
{
    int i,j=0;
    char symbol;
    ipush('#');
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':ipush(symbol);
                     break;
            case ')':while(istack[tos]!='(')
                     postfix[j++]=ipop();
                     ipop();
                     break;
            case '^':
            case '*':
            case '/':
            case '%':
            case '+':
            case '-':while(precd(symbol)<=precd(istack[tos]))
                     postfix[j++]=ipop();
                     ipush(symbol);
                     break;
            default: postfix[j++]=symbol;
        }
    }
    while(istack[tos]!='#')
        postfix[j++]=ipop();
        postfix[j]='\0';
}
void push(float ele)
{
    stack[++top]=ele;
}
float pop()
{
    return (stack[top--]);
}
void evaluate(char postfix[50])
{
    int i;
    char sym;
    float op1,op2,res,x;
    for(i=0;i<strlen(postfix);i++)
    {
        sym=postfix[i];
        if(isalpha(sym))
        {
            printf("Enter the value for %c=",sym);
            scanf("%f",&x);
            push(x);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(sym)
            {
            case '+':push(op1+op2);
                      break;
            case '-':push(op1-op2);
                      break;
            case '*':push(op1*op2);
                      break;
            case '/':push(op1/op2);
                      break;
            case '%':push((int)op1%(int)op2);
                      break;
            case '^':push(pow(op1,op2));
                      break;
            default:printf("Invalid postfix exp");
                    exit(0);
            }
        }
    }
    res=pop();
    printf("Expression after evaluation %f",res);
}
int main() {
    char infix[20],postfix[20];
    printf("Enter infix=\n");
    gets(infix);
    convertip(infix,postfix);
    printf("Postfix exp=%s\n",postfix);
    evaluate(postfix);
    return 0;
}
