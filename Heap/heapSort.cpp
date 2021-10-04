#include <iostream>
using namespace std;

class Minheap
{
public:
    // Data members
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximmum possible size of min heap
    int heap_size; // current number of elements in min heap

    Minheap(int cap)
    {
        heap_size = 0; // initially heap size is 0
        capacity = cap;
        harr = new int[cap]; // create heap array
    }

    // Parent node
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // Left child node
    int left(int i)
    {
        return (2 * i + 1);
    }

    // Right child node
    int right(int i)
    {
        return (2 * i + 2);
    }

    // Get minimum from the heap
    int getMin()
    {
        return harr[0];
    }

    // Printing array (min heap)
    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }

    // INSERTION
    void insertKey(int k)
    {
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k; // insert at last pos

        //check if mean heap property is followed
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[i])
            smallest = l;

        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            heapify(smallest); // Recursive call to rearrange the heap
        }
    }

    // EXTRACT MIN
    int extractMin()
    {
        if (heap_size <= 0)
            return INT16_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        // Store the minimum value
        int root = harr[0];

        // make root = last node's value
        harr[0] = harr[heap_size - 1];

        // reduce heap size
        heap_size--;

        // restructure heap
        heapify(0);

        return root;
    }

};

void heapSort(int *a, int n){
    // Take the array size and values from the user and create a minheap
    Minheap obj(n);
    int i = 0;

    // Insert the values in the min heap
    while(i < n){
        obj.insertKey(a[i]);
        i++;
    }
    
    // obj.heapify(0);
    i = 0;

    // Bring the minimum element at top and extract
    // Extracting will remove the min element
    // and place the extracted element at its correct position
    while(i < n && obj.heap_size != 0){
        a[i] = obj.extractMin();
        i++;
    }

    // Print the sorted array
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);
    
    return 0;
}