#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[100];
    int i=0, num1, num2, result;
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    while (postfix[i]!='\0')
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            num1 = pop();
            num2 = pop();
            if (postfix[i]=='+')
            {
                result = num2 + num1;
            }
            else if (postfix[i]=='-')
            {
                result = num2 - num1;
            }
            else if (postfix[i]=='*')
            {
                result = num2 * num1;
            }
            else if (postfix[i]=='/')
            {
                result = num2 / num1;
            }
            push(result);
        }
        i++;
    }
    printf("Result: %d", pop());
    
}
