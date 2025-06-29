#include <stdio.h>
#include <stdlib.h>

// Sorts an array using the Selection Sort algorithm. Pass the array and the length
// Best Time Complexity: O(n²) Worst Time: O(n²), Space complexity O(1), Not stable.
void selection_sort(int array[], int len)
{
    // Outer loop iterates through each element of the array, except the last one
    for (int i = 0; i < len - 1; i++)
    {
        // Assume the current index 'i' holds the smallest element
        int min = i;

        // Inner loop scans the unsorted part of the array to find the real minimum
        for (int j = i + 1; j < len; j++)
        {
            // If we find a smaller element, update the index of the minimum
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        // If the minimum is not already in position i, swap it with the element at i
        if (min != i)
        {
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

// Sorts an array using the Bubble Sort algorithm. Pass the array and the length
// Best Time Complexity: O(n), Worst Time: O(n²), Space Complexity: O(1), Stable.
void bubble_sort(int array[], int len)
{
    // Outer loop: each pass ensures the next-largest element "bubbles" to its correct position
    for (int i = 0; i < len - 1; i++)
    {
        // A flag to track whether any swaps occurred during this pass
        bool swapped = false;

        // Inner loop: compare adjacent elements and swap if needed
        // The '- i' means we don't need to check the last i elements, as they're already sorted
        for (int j = 0; j < len - i - 1; j++)
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
        if (!swapped)
        {
            return;
        }
    }
}

// Sort an array using the Insertion Sort algorithm. Pass the array and length
// Best Time Complexity: O(n), Worst Time: O(n²), Space complexity O(1), Stable.
void insertion_sort(int array[], int n)
{
    for (int i = 1; i < n; i++) // Start from second element
    {
        int key = array[i]; // Key to insert
        int j = i - 1;      // Start from element before key

        // Shift elements of the sorted section to the right
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j]; // Move the bigger element right
            j--;                     // Check the next one to the left
        }

        array[j + 1] = key; // Insert key into correct spot
    }
}

// Recursively sorts the array using Merge Sort. Pass the array, the first index and the last index.
// Best Time Complexity: O(n log n), Worst Time: O(n log n), Space complexity: O(n), Stable.
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

// Recursively sorts the array by partitioning it around a pivot element,
// then independently sorts the subarrays left and right of the pivot.
// You can choose between different pivot strategies: fixed (end), randomized, median-of-three, or introsort.
// Best Time Complexity: O(n log n), Worst Time: O(n²) (rare with good pivots),
// Space complexity: O(log n) due to recursion stack, Not stable.
void quick_sort(int array[], int start, int end)
{
    // Base case, with 0 or 1 element, the array is already sorted
    if (start >= end)
    {
        return;
    }

    // randomized_pivot(array, start, end);         // Sets the random pivot at array[end]
    // median_of_three(array, start, end);          // Sets the median of start, mid and end as pivot at array[end]
    int pivot = partition(array, start, end); // Call partition and get the pivot
    quick_sort(array, start, pivot - 1);      // Sort left of pivot
    quick_sort(array, pivot + 1, end);        // Sort right of pivot
}

// Randomizes the pivot selection to reduce the chance of Quick Sort hitting worst-case O(n²)
// on already sorted or adversarial inputs, improving average-case performance.
// Call srand(time(NULL)); once at the beginning of your main() to ensure randomization is seeded properly.
// This ensures a different sequence of random pivots across program executions.
void randomized_pivot(int array[], int start, int end)
{
    // Choose a random pivot index between start and end
    int random_index = start + rand() % (end - start + 1);

    // Swap the randomly chosen pivot with the element at the end
    int temp = array[end];
    array[end] = array[random_index];
    array[random_index] = temp;
}

// Improves pivot choice by selecting the median of three elements,
// often balancing partitions better and reducing worst cases like already sorted or reverse-sorted input.
void median_of_three(int array[], int start, int end)
{
    int a = array[start];
    int b = array[(start + end) / 2];
    int c = array[end];

    int median_index;

    // Finds the median of three values
    if ((a <= b && b <= c) || (c <= b && b <= a))
    {
        median_index = (start + end) / 2;
    }
    else if ((b <= a && a <= c) || (c <= a && a <= b))
    {
        median_index = start;
    }
    else
    {
        median_index = end;
    }

    // Moves it to the end of the segment to use as pivot
    int temp = array[end];
    array[end] = array[median_index];
    array[median_index] = temp;
}

// Chooses a pivot (last element) and rearranges the array so that
// all elements smaller than the pivot come before it, and all larger come after.
// Returns the index where the pivot finally lands after partitioning.
int partition(int array[], int start, int end)
{
    int pivot = array[end]; // Choose the last element as pivot

    // i marks the boundary of elements less than the pivot.
    // Elements <= i are less than pivot; elements > i and < j are greater or equal.
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            // Swap array[i] and array[j]
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    // Place the pivot in its correct sorted position
    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;

    // Return the partition index
    return i + 1;
}

// An efficient, in-place comparison-based sorting algorithm using a binary heap structure
// Useful for guaranteed O(n log n) performance without extra memory.
// Best Time Complexity: O(n log n), Worst Time Complexity: O(n log n), Space Complexity: O(1), Not Stable.
void heap_sort(int array[], int len)
{
    build_max_heap(array, len);

    for (int i = len - 1; i > 0; i--)
    {
        // Move current max (root) to the end
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        // Re-heapify the reduced heap (excluding the sorted elements at the end)
        heapify(array, i, 0);
    }
}

// Build a max heap from an unordered array.
// Starts from the last non-leaf node down to root,
// calling heapify to ensure subtree satisfies max-heap property.
void build_max_heap(int array[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(array, len, i);
    }
}

// Sift down the index 'i' to it's correct position
void heapify(int array[], int heap_size, int i)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    // Check if left child index is inside heap and if left child is greater than parent
    if ((left < heap_size) && (array[left] > array[largest]))
    {
        largest = left;
    }

    // Check if right child index is inside heap and if right child is greater than current largest
    if ((right < heap_size) && (array[right] > array[largest]))
    {
        largest = right;
    }

    // If largest is not the parent, swap and recurse to maintain max-heap property
    if (largest != i)
    {
        int temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;

        heapify(array, heap_size, largest);
    }
}