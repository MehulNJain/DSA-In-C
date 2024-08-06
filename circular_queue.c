#include<stdio.h>
#include<stdlib.h>
#define size 5

int cq[size];
int front=-1;
int rear=-1;

void enqueue()
{
    if (front==(rear+1)%size)
    {
        printf("Circular Queue Overflow !!!\n");
        return;
    }
    if (front==-1&&rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%size;
    }
    printf("Enter Value: ");
    scanf("%d",&cq[rear]);
}

void dequeue()
{
    if (front==-1&&rear==-1)
    {
        printf("Circualr Queue Underflow !!!\n");
        return;
    }
    if (front==rear)
    {
        printf("%d is deleted\n",cq[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("%d is deleted",cq[front]);
        front=(front+1)%size;
    }
}

void display()
{
    int i=front;
    if (front==-1&&rear==-1)
    {
        printf("Circular Queue is Empty !!!\n");
    }
    else
    {
        printf("\nCircular Queue Elements are: \n");
        while (i!=rear)
        {
            printf("%d\n",cq[i]);
            i=(i+1)%size;
        }
        printf("%d\n",cq[i]);
    }
}

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

            default:
            printf("Invalid choice !!!\n");
        }
    }
    return 0;
}