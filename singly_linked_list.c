#include<stdio.h>
#include<stdlib.h>

struct node
{
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
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new_node->data);

    if (start==NULL)
    {
        new_node->next=NULL;
        start=new_node;
    }
    else 
    {
        new_node->next=start;
        start=new_node;
    }
}

void insert_end()
{
    struct node * new_node,* temp;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new_node->data);

    if(start==NULL)
    {
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
        new_node->next=NULL;
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

void insert_after()
{
    int ele;
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    temp = start;

    printf("Enter the node after which to insert: ");
    scanf("%d", &ele);

    while(temp != NULL && temp->data != ele)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &new_node->data);

    new_node->next = temp->next;
    temp->next = new_node;
}

void display()
{
    struct node*temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void delete()
{
    int ele;
    struct node *ptemp,*temp;
    printf("Enter node to delete: ");
    scanf("%d", &ele);
    if (ele==start->data)
    {
        temp=start;
        start=start->next;
        free(temp);
    }
    else
    {
        temp=start;
        while (temp->data!=ele)
        {
            ptemp=temp;
            temp=temp->next;
        }
        ptemp->next=temp->next;
        free(temp);
    }
}


