#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL, *rear=NULL;

void enqueue();
void dequeue();
void display();

int main()
{
    int k;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            enqueue();
            display();
            break;

            case 2:
            dequeue();
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

void enqueue()
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&new_node->data);

    if (front==NULL&&rear==NULL)
    {
        new_node->next=NULL;
        rear=new_node;
        front=new_node;
    }
    else
    {
        rear->next=new_node;
        new_node->next=NULL;
        rear=new_node;
    }
}

void dequeue()
{
    struct node *temp;
    if (front==NULL&&rear==NULL)
    {
        printf("Queue Underflow!!!");
    }
    else if (front==rear)
    {
        temp=front;
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=front;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}