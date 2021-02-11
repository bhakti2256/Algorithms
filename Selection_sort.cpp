#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements you want in an array: ";
    cin>>n;
    int a[n];

    //Take array input
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //Selection sort
    int min; //to keep track of minimum elem in an array
    for(int i=0;i<n-1;i++) //for comparing all other elements with element at i
    {
        min = i;
        for(int j=i+1;j<n;j++) //for iterating from sub-array which is unsorted
        {
            if(a[j] < a[min]) //do if(a[i] > a[min]) for sorting in descending order
            {
                min = j; //assigning min index to smallest elem
            }
        }
        if (min != i)
        {
            swap(a[min],a[i]); //swapping min elem at ith index
        }
        
    }

/* Simple Algo:
Selection sort -

for(int i=0;i<n-1;i++)
{
    for(int j=i+1; j<n; j++) //do if(a[i] < a[j]) for sorting in descending order
    {
        if(a[i] > a[j])
        {
            swap(a[i], a[j]);
        }
    }
}
*/

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}