#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void insertionSort(vector<int>& array, int length)
{
    int temp;
    for (int i = 1; i < length; i++)
    {
        temp = array[i];
        int j = i - 1;
        while (j > -1 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    return;
}

int main()
{
    int inputSize;
    cout<<"Enter input size  : ";
    cin>>inputSize;
    int inputValue = 0;
    vector<int> array;
    for(int i = 0; i<inputSize; i++)
    {
        cout<<"Enter value : ";
        cin>>inputValue;
        array.push_back(inputValue);

        int size = array.size();
        insertionSort(array, size);
        if(size % 2 != 0)
        {
            int medianIndex;
            if(size == 1)
            {
                medianIndex = 0;
            }
            else
            {
                medianIndex = (array.size()/2);
            }
            double median = array[medianIndex]*1.0;
            cout<<"Array\tMedian"<<endl;
            cout<<"[";
            for(int i = 0; i<array.size(); i++)
            {
                cout<<array[i]<<",";
            }
            cout<<"]\t"<<median<<endl;
        }
        else
        {
            double median = (array[(array.size()/2)-1] + array[(array.size()/2)])*1.0/2; 
            cout<<"Array\tMedian"<<endl;
            cout<<"[";
            for(int i = 0; i<array.size(); i++)
            {
                cout<<array[i]<<",";
            }
            cout<<"]\t"<<median<<endl;
        }
    }
    return 0;
}