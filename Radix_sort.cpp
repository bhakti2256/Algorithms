#include <iostream>
using namespace std;

void RadixSort(int a[], int n);
int GetMax(int a[], int n);
void CountingSort(int a[], int n, int div);

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    RadixSort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}

void RadixSort(int a[], int n)
{
    int m = GetMax(a,n);
    for(int div=1; m/div > 0; div *= 10)
    {
        CountingSort(a,n,div);
    }
}

int GetMax(int a[], int n)
{
    int max = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}

void CountingSort(int a[], int n, int div)
{
    //int range = 10;
    int count[10] = {0};    //Declaring count_array to find occurences of an element in an array
    int output_array[n]; //Output_array

    /*for (int i = 0; i < range; i++) //Initialising count array to 0;
    {
        count[i] = 0;
    }*/

    for (int j = 0; j < n; j++) //Updating counts/frequency of elements in count array
    {
        count[(a[j]/div)%10]++;
    }

    for (int k = 1; k < 10; k++) //Calculating cumulative frequencies of count array to get correct positions of array elements
    {
        count[k] = count[k] + count[k - 1];
    }

    for (int l = (n-1); l >= 0; l--) //adding elements in sorted way to output_array
    {
        output_array[count[(a[l]/div)%10]-1] = a[l];
        count[(a[l]/div)%10]--;
    }

    for (int p = 0; p < n; p++)
    {
        a[p] = output_array[p];
    }
}