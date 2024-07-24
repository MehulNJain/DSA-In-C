#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char c)
{
    top=top+1;
    stack[top]=c;

}

char pop()
{
    return stack[top--];

}

int precedence(char op)
{
    if (op == '*' || op =='/')
    {
          return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else 
    return 0;
}

int main()
{
    char expr[100];
    int i = 0;
    char x;
    printf("Enter infix expression");
    scanf("%s",expr);

    while(expr[i]!='\0')
    {
        if (isalnum(expr[i]))
        {
            printf("%c",expr[i]);
        }
        else if ((expr[i])=='(')
        {
            push (expr[i]);
        }
        else if ((expr[i])==')')
        {
            while((x=pop()) !='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while (precedence (stack[top])>=precedence (expr[i]))
            {
                printf("%c",pop());
            }
            push (expr[i]);
        }
        i++;

    }   
    while (top!= -1)
    {
        printf("%c",pop());
    } 
    printf("\n");
    return 0;
}
