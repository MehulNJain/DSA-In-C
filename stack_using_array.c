#include <stdio.h>
#include<stdlib.h>

int stack[4];
int top = -1;

void push(int item) {
    if (top == 4) {
        printf("Stack Overflow! Cannot push %d\n\n", item);
    } else {
        stack[++top] = item;
        printf("Pushed %d into the stack\n\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n\n");
    } else {
        int popped_item = stack[top--];
        printf("Popped %d from the stack\n\n", popped_item);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n\n");
    } else {
        printf("Stack elements are:\n\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int k,ele;
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d",&ele);
            push(ele);
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