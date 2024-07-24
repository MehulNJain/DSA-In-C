#include <stdio.h>
int stack[100];
int top=-1;
char str[100];
void push(char item)
{
  stack[++top]=item;
}
void pop()
{
  top--;
}
void check_balance()
{
  if(top==-1)
  {
    printf("\n Stack is balanced");
  }
  else
  {
    printf("\n Stack is not balanced");
  }
}
int main()
{
  int i=0;
  printf("Enter the expression:-\n");
  scanf("%s",str);
  while(str[i]!='\0')
  {
    if(str[i]=='(')
    {
      push(str[i]);
    }
    if(str[i]==')')
    {
      pop(str[i]);
    }
    i++;
  }
  check_balance();
  return 0;
}



  
  
  
  
  