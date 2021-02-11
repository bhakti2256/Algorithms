#include<iostream>
using namespace std;

//Quick-sort algo

int Partition(int arr[], int s, int e) //return index position for next partition
{
    int pivot = arr[e]; //select last element as pivot
    int pindex = s; //to keep track of smaller elements in array and will swap when element smaller than pivot is found

    for(int i=s; i<e ; i++) //will compare all elements with last elem(pivot)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }

    swap(arr[e],arr[pindex]); //swapping pivot element to its correct position
    return pindex; 
}

void QuickSort(int a[],int s, int e) 
{
    //s = start-index & e = end-index
    if(s<e) //checking if s < e 
    {
        int p = Partition(a,s,e);
        QuickSort(a,s,(p-1)); //recursice call for left partition
        QuickSort(a,(p+1),e); //recursice call for right partition
    }

}

int main()
{
    int size;
    cout<<"Enter size: ";
    cin>>size;
    int a[size];

    cout<<"Enter elements: ";
    for(int i=0 ; i<size ; i++)
    {
        cin>>a[i];
    }

    cout<<"\nBefore Sorting: ";
    for(int i=0 ; i<size ; i++)
    {
        cout<<a[i]<<" ";
    }

    QuickSort(a,0,(size-1)); // passing array,start-index,end-index

    cout<<"\nAfter Sorting: ";
    for(int i=0 ; i<size ; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}