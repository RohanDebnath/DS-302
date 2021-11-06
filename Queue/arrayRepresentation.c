#include <stdio.h>
#include <stdlib.h>
typedef struct stud
{
    int size, front, rear;
    int *arr;
} Queue;
Queue *queue_pointer;
int isFull()
{
    if (queue_pointer->rear == queue_pointer->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
int isEmpty()
{
    if (queue_pointer->front == queue_pointer->rear)
    {
        return 1;
    }
    else
        return 0;
}
void enque(int data)
{
    if (isFull() == 1)
    {
        printf("Stack Overflow !! cannot push anymore\n");
    }
    else
    {
        queue_pointer->rear++;
        queue_pointer->arr[queue_pointer->rear] = data;
        printf("Item Enqueued\n");
    }
}
int dequeue()
{
    int val;
    if (isEmpty() == 1)
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        queue_pointer->front++;
        val = queue_pointer->arr[queue_pointer->front];
        return val;
    }
}
void display(int count)
{
    printf("Printing Queue elements\n");
    for (int i = 1; i <=count; i++)
    {
        printf("|%d| ",queue_pointer->arr[i]);
    }
    printf("\n");
}
int main()
{
    queue_pointer = (Queue *)malloc(sizeof(Queue));
    queue_pointer->size = 10;
    queue_pointer->front = queue_pointer->rear = 0;
    queue_pointer->arr = (int *)malloc(queue_pointer->size * sizeof(int));
    int choice = 0, data, ret_val = 0, count=0;
    while (choice != 4)
    {
        printf("\nPress\n1 for Enqueue\n2 for Dequeue\n3 for display\n4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter you dara to enqueue\n");
            scanf("%d", &data);
            enque(data);
            count++;
            break;
        case 2:
            ret_val = dequeue();
            printf("Value dequeue is %d\n", ret_val);
            count--;
            break;
        case 3:
            display(count);
            break;
        case 4:
        printf("Exit Done\n");
            exit(0);
            break;
        default:
            printf("Wrong selection of choice\n");
        }
    }
}