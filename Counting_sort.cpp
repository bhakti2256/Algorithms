#include <iostream>
using namespace std;

void Counting_sort(int a[], int n, int range)
{
    int count[range];    //Declaring count_array to find occurences of an element in an array
    int output_array[n]; //Output_array

    for (int i = 0; i < range; i++) //Initialising count array to 0;
    {
        count[i] = 0;
    }

    for (int j = 0; j < n; j++) //Updating counts/frequency of elements in count array
    {
        ++count[a[j]];
    }

    for (int k = 1; k < range; k++) //Calculating cumulative frequencies of count array to get correct positions of array elements
    {
        count[k] = count[k] + count[k - 1];
    }

    for (int l = 0; l < n; l++) //adding elements in sorted way to output_array
    {
        output_array[--count[a[l]]] = a[l];
    }

    /*for(int m=0;m<n;m++)
    {
        cout<<output_array[m]<<" ";
    }*/

    for (int p = 0; p < n; p++)
    {
        a[p] = output_array[p];
    }
}

int main()
{
    int n, range;
    cout << "Enter the number of elements you want in an array: ";
    cin >> n;

    cout << "Enter range of elements from 0: 0 to ";
    cin >> range;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Counting_sort(a, n, range);

    for (int m = 0; m < n; m++)
    {
        cout << a[m] << " ";
    }

    return 0;
}