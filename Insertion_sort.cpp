#include<iostream>
using namespace std;

void insertionSort(int a[], int n);

int main()
{
    int n;
    cout<<"Enter number of elements you want in an array: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    insertionSort(a,n);

    cout<<"Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}

void insertionSort(int a[], int n)
{
    int i,j,key;
    for(i=1; i<n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}