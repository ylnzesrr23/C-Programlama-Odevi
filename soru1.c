#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

// Insertion Sort
void insertionSort(int dizi[], int n)
{
    int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = dizi[i];
        j = i - 1;

        while(j >= 0 && dizi[j] > key)
        {
            dizi[j + 1] = dizi[j];
            j--;
        }

        dizi[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int dizi[], int n)
{
    int i, j, minIndex, temp;

    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(dizi[j] < dizi[minIndex])
            {
                minIndex = j;
            }
        }

        temp = dizi[i];
        dizi[i] = dizi[minIndex];
        dizi[minIndex] = temp
