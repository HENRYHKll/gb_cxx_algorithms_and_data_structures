#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a    = *b;
    *b    = t;
}

int* median(int* a, int* b, int* c)
{
    if ((*b < *a && *a < *c) || (*b > *a && *a > *c))
        return a;
    if ((*a < *b && *b < *c) || (*a > *b && *b > *c))
        return b;
    return c;
}
void improvedQuickSort(int* arr, int first, int last)
{
    if ((last - first) > 10)
    {
        int i   = first;
        int j   = last;
        int mid = (i + j) / 2;

        swap(&arr[mid], median(&arr[i], &arr[mid], &arr[j]));

        int x = arr[mid];

        do
        {
            while (arr[i] < x)
                i++;
            while (arr[j] > x)
                j--;

            if (i <= j)
                swap(&arr[i++], &arr[j--]);
        } while (i <= j);

        if (i < last)
            improvedQuickSort(arr, i, last);
        if (first < j)
            improvedQuickSort(arr, first, j);
    }
    else
    {
        int temp, pos;
        for (int i = (first + 1); i <= last; ++i)
        {
            temp = arr[i];
            pos  = i - 1;
            while (pos >= 0 && arr[pos] > temp)
            {
                arr[pos + 1] = arr[pos];
                pos--;
            }
            arr[pos + 1] = temp;
        }
    }
}

void evenBucketSort(int* arr, int len)
{
    const int max = len;
    const int b   = 10;

    int buckets[b][max + 1];

    for (int i = 0; i < b; ++i)
        buckets[i][max] = 0;

    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (int i = 0; i < max; ++i)
        {
            int d = (arr[i] / digit) % b;
            if (arr[i] % 2 == 0)
                buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < buckets[i][max];)
            {
                if (arr[idx] % 2 == 0)
                    arr[idx++] = buckets[i][j++];
                else
                    idx++;
            }
            buckets[i][max] = 0;
        }
    }
}

void fillRandom(int* array, const int len, const int border)
{
    srand(time(NULL));
    for (int i = 0; i < len; ++i)
        *(array + i) = rand() % border;
}

void printArray(int* array, const int size, const int offset)
{
    char format[5];
    sprintf(format, "%%%dd", offset);

    for (int i = 0; i < size; ++i)
        printf(format, *(array + i));
    printf("\n");
}

void task1()
{
    printf("Improved quick sort:\n");
    const int SZ      = 10;
    const int offset  = 4;
    const int randNum = 999;
    int       arr[SZ];
    fillRandom(arr, SZ, randNum);
    printArray(arr, SZ, offset);
    improvedQuickSort(arr, 0, SZ - 1);
    printArray(arr, SZ, offset);
}

void task2()
{
    printf("Block sorting algorithm for even numbers:\n");
    const int SZ      = 10;
    const int offset  = 4;
    const int randNum = 999;
    int       arr[SZ];
    fillRandom(arr, SZ, randNum);
    printArray(arr, SZ, offset);
    evenBucketSort(arr, SZ);
    printArray(arr, SZ, offset);
}

int main(const int argc, const char** argv)
{
    task1();
    task2();

    return 0;
}
