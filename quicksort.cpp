#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int> &array, int start, int end)
{
    int i, temp, j, pivot;
    i = start - 1;
    for (j = start; j < end; j++)
    {
        if (array[j] < array[end])
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    return i;
}

void quickSort(vector<int> &array, int start, int end)
{
    if (end <= start)
        return;

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}

void quickSortIterative(vector<int> &array, int start, int end)
{
    vector<int> stack(end - start + 1);
    int top = -1;

    top++;
    stack[top] = start;
    top++;
    stack[top] = end;

    while (top > -1)
    {
        end = stack[top];
        top--;
        start = stack[top];
        top--;

        int pivot = partition(array, start, end);
        if (pivot - 1 > start)
        {
            top++;
            stack[top] = start;
            top++;
            stack[top] = pivot - 1;
        }

        if (pivot + 1 < end)
        {
            top++;
            stack[top] = pivot + 1;
            top++;
            stack[top] = end;
        }
    }
}

int main()
{
    const int len = 50000;
    vector<int> arr1(len);
    vector<int> arr2(len);
    srand(time(NULL));

    int sumOfTimeRec = 0;
    int sumOfTimeIter = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int i = 0; i < len; i++)
        {
            arr1[i] = rand();
            arr2[i] = arr1[i];
        }
        auto start = high_resolution_clock::now();
        quickSort(arr1, 0, len - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        sumOfTimeRec += duration.count();

        start = high_resolution_clock::now();
        quickSortIterative(arr2, 0, len - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        sumOfTimeIter += duration.count();
    }

    int averageTimeRec = sumOfTimeRec / 100;
    int averageTimeIter = sumOfTimeIter / 100;
    cout << "Time taken by quick sort(rec) for " << len << " elements : " << averageTimeRec << endl;
    cout << "Time taken by quick sort for(iter) " << len << " elements : " << averageTimeIter << endl;
    return 0;
}
