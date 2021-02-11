#include<iostream>
using namespace std;

void mergeSort(int a[],int l, int r,int n);
void merge(int a[],int l, int m, int r,int n);

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    mergeSort(a,0,n-1,n);

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }    
}

void mergeSort(int a[],int l, int r,int n) //Recursive function to divide the array l=left, r = right, n = size of array
{
    if(l<r) //base case - when there will be one element -> l=r so we need to stop the recursive call
    {
        int m = (l+r)/2; //middle element
        mergeSort(a,l,m,n); //recursive call for first half
        mergeSort(a,m+1,r,n); //recursive call for second half
        merge(a,l,m,r,n); 
    }
}

void merge(int a[],int l, int m, int r,int n) //function to merge two sub-arrays
{
    int i,j,k;
    i = l; // i -> 1st element of left sub-array 
    j = m+1; // j -> 1st element of right sub-array
    k = l; // k -> keep track of temp arrray
    int temp[n]; 

    while(i<=m && j<=r) //as partitions are uneven, at one point one sub-array will be completely exhausted and thus this loop will stop 
    {
        if(a[i] <= a[j]) //comparison of elements 
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
 
    //two loops to put the left-over sub-arrays in temp array 
    while(i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    
    //loop to update original array with sorted array(i.e. temp array)
    for(int p=l; p<=r; p++)
    {
        a[p] = temp[p];
    }
}