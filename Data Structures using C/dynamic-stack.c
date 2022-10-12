#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void display(struct node *top)
{
       if(top == NULL){
           printf("\nNothing to display ,stack is empty: ");
       }
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
}
void push(struct node **top, int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("\nStack is Full ");
    }
    temp->data = num;
    temp->next = *top;
    *top = temp;
}
void Pop(struct node **top)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = *top;
    if (temp == NULL)
    {
        printf("\nStack is Empty ");
    }
    else
    {
        *top = temp->next;
        free(temp);
    }
}
void del_stack(struct node **top)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = *top;

    if (*top == NULL)
        return;
    while (*top != NULL)
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main()
{
    int choice, data;
    struct node *top;
    top = NULL;
    printf("\n 1.Push\n 2.Pop\n 3.delete stack\n 4.Display\n");
    while (1)
    {

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data you want to add : ");
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:

            Pop(&top);
            break;

        case 3:

            del_stack(&top);
            break;

        case 4:

            display(top);
            break;

        default:
            printf("\nEnter a valid choice !!!");
            break;
        }
    }

    return 0;
}
