#include <stdio.h>

int numbers[] = {4, 2, 9, 1, 3};
int n = 5;

void selection_sort(numbers)
{
    for (int i = 0; i < n - 1; i++) // i < n - 1 because the last number will be covered by 'j'
    {

        int min = i; // min is the flag to mark the min index in the array

        for (int j = i + 1; j < n; j++)
        {
            if (numbers[min] > numbers[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = numbers[i]; // temporary variable to swap the min index with i index
            numbers[i] = numbers[min];
            numbers[min] = temp;
        }
    }
}

void bubble_sort(numbers)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            return;
        }
    }
}

void merge_sort(numbers)
{
    if (len(numbers) == 1)
    {
        return;
    }
    int mid = len(array) / 2;
    int left[] = numbers[0, mid];
    int right[] = numbers[mid + 1, -1];
    int len_left = l int len_right = r int k = 0 for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (left[i] < right[j])
            {
                array[k] = left[i];
                k++;
            }
            else if (left[j] < right[i])
            {
                array[k] = left[j];
                k++;
            }
            else if (left[j] = right[i])
            {
                array[k] = left[i];
                array[k] = left[j];
                k += 2;
            }
        }
    }
}

void merge_sort(numbers, start, end)
{
}
