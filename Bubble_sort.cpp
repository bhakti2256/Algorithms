#include <iostream>
using namespace std;

void bubble_sort(int a[], int n);
void print(int a[], int n);

int main()
{
    int n;
    cout<<"Enter number of elements you want in an array: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    bubble_sort(a,n);
    print(a,n);
}

void bubble_sort(int a[], int n)
{
    bool flag = false; //for optimised bubble sort 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = true;
                swap(a[j],a[j+1]);
            }
        }
        if(flag == false) //flag will be true only when swapping will be done
            break; //flag is false means no swapping done and hence array is sorted
    }
}
void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}