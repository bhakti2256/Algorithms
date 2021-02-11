#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int num);

int main()
{
    int n;
    cout<<"Enter total number of elements you want in an array: ";
    cin>>n;
    int arr[n],num,pos;
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter element you want to search: ";
    cin>>num;

    //sort(arr,arr+n); //in-built sorting algorithm

    pos = binarySearch(arr,n,num);

    if(pos == 0)
        cout<<"Element not found :("<<endl;
    else
        cout<<"Element "<<num<<" found at position "<<pos+1<<endl;

    return 0;
}

int binarySearch(int a[], int n, int num)
{
    int low,mid,high;
    low = 0;
    high = n-1;
    
    while (low<=high)
    {
        mid = low + (high-low) / 2;
        if(a[mid] == num)
            return mid;
        else if(a[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
