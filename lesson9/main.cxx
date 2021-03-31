#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SZ 10
#define SIZE 1000
typedef struct
{
    int pr;
    int dat;
} Node;

extern Node* arr[SZ];
extern int   head;
extern int   tail;
extern int   items;
extern int   Stack[SIZE];
extern int   cursor;

int Stack[SIZE];
int cursor = -1;

bool PushStack(int data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("Stack overflow\n");
        return false;
    }
}

int PopStack()
{
    if (cursor != -1)
        return Stack[cursor--];
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void printStack()
{
    while (cursor > -1)
        printf("%d", PopStack());
}

Node* arr[SZ];
int   head;
int   tail;
int   items;

void init()
{
    for (int i = 0; i < SZ; ++i)
        arr[i] = NULL;

    head  = 0;
    tail  = -1;
    items = 0;
}

void ins(int pr, int dat)
{
    if (items == SZ)
        printf("Queue is full\n");
    else
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->dat  = dat;
        node->pr   = pr;

        arr[++tail] = node;
        items++;
    }
}

Node* rem()
{
    if (items == 0)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    else
    {
        int   idx  = head;
        int   flag = 0;
        Node* tmp  = arr[head];

        while (++idx < items)
            if (tmp->pr > arr[idx]->pr)
            {
                tmp  = arr[idx];
                flag = idx;
            }

        idx = flag;

        while (flag < items)
            arr[flag++] = arr[++idx];

        arr[tail--] = NULL;
        --items;

        return tmp;
    }
}

void printQueue()
{
    printf("[ ");
    for (int i = 0; i < SZ; ++i)
    {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

void task1()
{
    printf("Task 1:\n");

    init();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);

    printf("Array of the queue after adding elements:\n");
    printQueue();

    printf("Retrieving items from a queue array:\n");
    for (int i = 0; i < 7; ++i)
    {
        Node* n = rem();
        printf("pr = %d, dat = %d\n", n->pr, n->dat);
        free(n);
    }

    printf("Array of the queue after retrieving the elements:\n");
    printQueue();

    ins(1, 110);
    ins(3, 120);
    ins(6, 130);

    printf("Array of the queue after adding elements:\n");
    printQueue();

    printf("Retrieving items from a queue array:\n");
    for (int i = 0; i < 5; ++i)
    {
        Node* n = rem();
        printf("pr = %d, dat = %d\n", n->pr, n->dat);
        free(n);
    }

    printf("Array of the queue after retrieving the elements:\n");
    printQueue();
}
void intToBin(unsigned int n)
{
    PushStack(n % 2);
    if (n > 1)
        intToBin(n / 2);
}

void task2()
{
    printf("\nЗадание 2:\n");
    unsigned int num = 0;
    printf("Please enter a whole positive decimal number: ");
    scanf("%d", &num);
    intToBin(num);
    printf("Binary representation of a number %d: ", num);
    printStack();
}

int main(const int arc, const char** argv)
{
    task1();
    task2();

    return 0;
}
