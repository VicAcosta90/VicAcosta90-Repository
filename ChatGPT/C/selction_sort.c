#include <stdio.h>

// Sorts an array using the Selection Sort algorithm. Pass the array and the length
void selection_sort(int array[], int n)
{
    // Outer loop iterates through each element of the array, except the last one
    for (int i = 0; i < len - 1; i++)
    {
        // Assume the current index i holds the smallest element
        int min = i;

        // Inner loop scans the unsorted part of the array to find the real minimum
        for (int j = i + 1; j < len; j++)
        {
            // If we find a smaller element, update the index of the minimum
            if (numbers[min] > numbers[j])
            {
                min = j;
            }
        }

        // If the minimum is not already in position i, swap it with the element at i
        if (min != i)
        {
            int temp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = temp;
        }
    }
}

// Sorts an array using the Bubble Sort algorithm. Pass the array and the length
void bubble_sort(int array[], int n)
{
    // Outer loop: each pass ensures the next-largest element "bubbles" to its correct position
    for (int i = 0; i < n - 1; i++)
    {
        // A flag to track whether any swaps occurred during this pass
        bool swapped = false;

        // Inner loop: compare adjacent elements and swap if needed
        // The '- i' means we don't need to check the last i elements, as they're already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            // If the current element is greater than the next, swap them
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                // Mark that a swap has happened
                swapped = true;
            }
        }

        // Optimization: if no swaps occurred during the inner loop, the array is already sorted
        if (swapped == false)
        {
            return;
        }
    }
}

// Recursively sorts the array using Merge Sort
void merge_sort(int array[], int start, int end)
{
    // Base case: if the array has one or zero elements, it's already sorted
    if (start >= end)
    {
        return;
    }

    // Find the middle index of the current portion of the array
    int mid = (start + end) / 2;

    // Recursively sort the left and the right halves, then merged the two sorted halves together
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);
    merge(array, start, mid, end);
}

// Merging two sorted halves
void merge(int array[], int start, int mid, int end)
{
    // Calculate the lengths of the two subarrays
    int len_left = mid - start + 1;
    int len_right = end - mid;

    // Temporary arrays to hold the left and right halves
    int left[len_left];
    int right[len_right];

    // Fill the left[] array with elements from start to mid
    int l = 0;
    for (int i = start; i <= mid; i++)
    {
        left[l] = array[i];
        l++;
    }

    // Fill the right[] array with elements from mid+1 to end
    int r = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        right[r] = array[i];
        r++;
    }

    // Merge the temporary arrays back into the original array
    int i = 0;     // Index for left[]
    int j = 0;     // Index for right[]
    int k = start; // Index for main array (from start to end)

    // Compare elements from left and right arrays, and insert the smallest one
    while (i < len_left && j < len_right)
    {
        // It's '<=' in case the two values are equal
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
            (left[i] > right[j])
            {
                array[k] = right[j];
                j++;
            }
        k++;
    }

    // Copy any remaining elements from left[], if any
    while (i < len_left)
    {
        array[k] = left[i];
        k++;
        i++;
    }

    // Copy any remaining elements from right[], if any
    while (j < len_right)
    {
        array[k] = right[j];
        k++;
        j++;
    }
}
