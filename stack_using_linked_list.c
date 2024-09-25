#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void display();

int main()
{
   int k,ele;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            push();
            display();
            break;

            case 2:
            pop();
            display();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
        }
    }
    return 0; 
}

void push()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to push: ");
    scanf("%d",&new_node->data);

    if (top==NULL)
    {
        top=new_node;
        new_node->next=NULL;
    }
    else
    {
        new_node->next=top;
        top=new_node;
    }
}

void pop()
{
    struct node *temp;
    if (top==NULL)
    {
        printf("Stack Underflow!!!");
    }
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}