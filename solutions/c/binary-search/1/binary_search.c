#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    int start = 0;
    int end = length;

    int total = start + end;
    int middle = total / 2;

    while (start <= end && length > 0 )
    {
        total = start + end;
        middle = total / 2;

        if (start == end)
        {
            if (arr[middle] == value)
                return &arr[middle];
            else
                break;
        }

        if (arr[middle] > value)
        {
            end = middle - 1;
            continue;
        }
        else if (arr[middle] < value)
        {
            start = middle + 1;
            continue;
        }
        else if (arr[middle] == value)
        {
            return &arr[middle];
        }

        printf("%d\n", arr[middle]);
    }

    return NULL;
}