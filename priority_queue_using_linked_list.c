#include<stdio.h>
#include<stdlib.h>

struct node
{
    int priority;
    int data;
    struct node*next;
};

struct node *front=NULL;

void enqueue();
void dequeue();
void display();

int main()
{
   int ch,x;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
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
            default:
                printf("\n\t Invalid number");
                break;
        }
    }
    return 0;
}

void display()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("\n%d %d",temp->priority,temp->data);
        temp=temp->next;
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("\nPriority queue is underflow");
        return ;
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
    }
}

void enqueue()
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter priority and data to insert: ");
    scanf("%d %d",&new_node->priority,&new_node->data);

    if(front==NULL)
    {
        front=new_node;
        new_node->next=NULL;
    }
    else
    {
        struct node *temp;
        if(new_node->priority<front->priority)
        {
            new_node->next=front;
            front=new_node;
        }
        else
        {
            temp=front;
            while((temp->next!=NULL && temp->next->priority<=new_node->priority))
            {
                temp=temp->next;
            }
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
}