#include <stdio.h> // do the delete at Index latter
#include <stdlib.h>
typedef struct stud
{
    int info;
    struct stud *next_link;
} Node;
Node *start = NULL;
void add_Node(int data)
{
    Node *newNode = NULL, *ptr;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->next_link = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        ptr = start;
        while (ptr->next_link != NULL)
        {
            ptr = ptr->next_link;
        }
        ptr->next_link = newNode;
    }
}
void display()
{
    Node *ptr;
    ptr = start;
    while (ptr)
    {
        printf("%d->", ptr->info);
        ptr = ptr->next_link;
    }
    printf("NULL\n");
}
int deletionAtBeginning()
{
    Node *ptr;
    ptr=start;
    start=start->next_link;
    free(ptr);
}
int deleteAtEnd()
{
    Node *ptr,*q;
    ptr=start;
    q=start->next_link;
    while(q->next_link!=NULL)
    {
        ptr->next_link;
        q->next_link;
    }
    ptr->next_link=NULL;
    free(q);
}
int main()
{
    int data;
    char user_choice;
    while (1)
    {
        printf("Want to insert new LinkLost ?press(y/n) if yes ");
        scanf("%c", &user_choice);
        if (user_choice == 'y' || user_choice == 'Y')
        {
            printf("Enter a data ");
            scanf("%d", &data);
            add_Node(data);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    display();
    deletionAtBeginning();
    display();
    deleteAtEnd();
    display();


}