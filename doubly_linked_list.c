#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node * start = NULL;

void insert_beg();
void insert_end();
void insert_after();
void delete();
void update();
void display();

int main()
{
    int choice;
    do
    {
        printf("1.Insert Beg\n2.Insert End\n3.Insert After\n4.Delete\n5.Update\n6.Display\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert_beg();
            display();
            break;
            case 2:
            insert_end();
            display();
            break;
            case 3:
            insert_after();
            display();
            break;
            case 4:
            delete();
            display();
            break;
            case 5:
            update();
            display();
            break;
            case 6:
            display();
            break;
            
        }
    }
    while (choice!=7);
}

void insert_beg()
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &new_node->data);
    if(start==NULL)
    {
        new_node->prev=NULL;
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        new_node->prev=NULL;
        new_node->next=start;
        start->prev=new_node;
        start=new_node;
    }
}

void insert_end()
{
    struct node *new_node, *temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &new_node->data);
    if (start==NULL)
    {
        new_node->prev=NULL;
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=NULL;
    }
}

void insert_after()
{
    struct node *new_node,*temp,*ntemp;
    int ele;
    printf("Enter Node: ");
    scanf("%d",&ele);
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &new_node->data);
    temp=start;
    while (temp->data!=ele)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=NULL;
    }
    else
    {
        ntemp=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=ntemp;
        ntemp->prev=new_node;
    }
}

void delete()
{
    int ele;
    struct node *ptemp,*ntemp,*temp;
    printf("Enter element to delete: ");
    scanf("%d",&ele);

    if(ele==start->data)
    {
        if(start->next==NULL)
        {
            temp=start;
            start=NULL;
            free(temp);
        }
        else
        {
            temp=start;
            start=start->next;
            start->prev=NULL;
            free(temp);
        }
    }
    else
    {
        temp=start;
        while(temp->data!=ele)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            ptemp=temp->prev;
            ptemp->next=NULL;
            free(temp);
        }
        else
        {
            ptemp=temp->prev;
            ntemp=temp->next;
            ptemp->next=ntemp;
            ntemp->prev=ptemp;
            free(temp);
        }
    }
}

void display()
{
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        printf("%d\t\t", temp->data);
        temp = temp->next;
    }
}

void update()
{
    struct node *temp;
    int ele;
    printf("Enter node which is to be updated: ");
    scanf("%d",&ele);
    temp=start;
    while (temp->data!=ele)
    {
        temp=temp->next;
    }
    printf("Enter new value: ");
    scanf("%d",&temp->data);
}
