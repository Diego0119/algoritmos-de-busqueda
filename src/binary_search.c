#include "header.h"

int iterative_binary_search(int arr[], int n, int target)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int recursive_binary_search(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] > target)
        return recursive_binary_search(arr, left, mid - 1, target);

    return recursive_binary_search(arr, mid + 1, right, target);
}
