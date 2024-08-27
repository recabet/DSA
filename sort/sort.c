#include "sort.h"

void selectionSort(int* arr, int size)
{
    int midx = 0;
    for (int i = 0; i < size; i++)
    {
        midx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[midx])
            {
                midx = j;
            }
        }
        const int temp = arr[i];
        arr[i] = arr[midx];
        arr[midx] = temp;
    }
}

void bubbleSort(int* arr, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int* arr, const int size)
{
    for (int i = 1; i < size; i++)
    {
        const int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void merge(int* arr, const int left, const int mid, const int right)
{
    int i, j;
    const int n1 = mid - left + 1;
    const int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, const int left, const int right)
{
    if (left < right)
    {
        const int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void quickSort(int* arr, const int size)
{
    constexpr int low = 0;
    const int high = size - 1;
    if (low < high)
    {
        const int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                const int temp = arr[++i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        const int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        const int pivotIndex = i + 1;
        quickSort(arr, pivotIndex);
        quickSort(arr + pivotIndex + 1, size - pivotIndex - 1);
    }
}
