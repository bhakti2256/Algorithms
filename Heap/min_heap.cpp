#include <iostream>
#include <math.h>
#include <conio.h>

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

    //  Height of min heap
    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }

    //  Searching
    bool linearSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == val)
            {
                return true;
            }
        }
        return false;
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

    // Helper function to delete key
    // This function brings the value to be removed at root
    void decreaseKey(int i, int new_val)
    {
        // minimize the val at index 'i' and bring it to the root
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // DELETION
    void deleteKey(int val)
    {
        if (linearSearch(val))
        {
            // get the index value of val
            int i = 0;
            while (i != val)
                i++;
            decreaseKey(i, INT16_MIN);

            // Remove the root by calling extract min
            extractMin();

            cout << "DELETION SUCCESSFUL:-)" << endl;
        }
        else
        {
            cout << "You have entered a key/value which is not in the heap\nDELETION UNSUCCESSFUL:-(" << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of min heap: ";
    cin >> n;
    Minheap obj(n); // Create a minheap object
    cout << "Min heap Created" << endl;

    int option, val, s;
    do
    {
        cout << "\n===OPERATION MENU====" << endl;
        cout << "\n1. Insert Node/Key" << endl;
        cout << "2. Search Node/Key" << endl;
        cout << "3. Delete Node/Key" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract min" << endl;
        cout << "6. Height of heap" << endl;
        cout << "7. Print Heap values" << endl;
        cout << "8. Clear screen" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 0:
            break;

        case 1:
            if (obj.heap_size == obj.capacity)
            {
                cout << "OVERFLOW: Heap is Full\nYour requested value can't be inserted:-(" << endl;
            }
            else
            {
                cout << "\nINSERT OPERATION" << endl;
                cout << "Enter the value to be inserted: ";
                cin >> val;
                obj.insertKey(val);
                cout << "INSERTION SUCCESSFULL:-)" << endl;
            }
            cout << "Press any key to continue...\n";
            getch();
            break;

        case 2:
            cout << "\nSEARCH OPERATION" << endl;
            cout << "Enter the value to search: ";
            cin >> val;
            if (obj.linearSearch(val))
                cout << "Value found:-)";
            else
                cout << "Value not found:-(";
            cout << endl;
            cout << "Press any key to continue...\n";
            getch();
            break;

        case 3:
            if (obj.heap_size <= 0)
                cout << "HEAP is EMPTY. \nNO DELETION POSSIBLE:-(";
            else
            {
                cout << "\nDELETE OPERATION" << endl;
                cout << "Enter the value to be deleted: ";
                cin >> val;
                obj.deleteKey(val);
            }
            cout << endl;
            cout << "Press any key to continue...\n";
            getch();
            break;

        case 4:
            cout << "\nThe minimum value from the heap: " << obj.getMin();
            cout << endl;
            cout << "Press any key to continue...\n";
            getch();
            break;

        case 5:
            cout << "\nEXTRACT MIN VALUE\n";
            s = obj.extractMin();
            if (s == INT16_MAX)
                cout << "No minimum element found\nHeap is empty!";
            else
                cout << "Minimum value extracted from HEAP is " << s;
            cout << endl;
            cout << "Press any key to continue...\n";
            getch();
            break;

        case 6:
            cout << "\nHEIGHT of Min heap created: " << obj.height();
            cout << endl;
            cout << "Press any key to continue...\n";
            getch();
            break;

        case 7:
            cout << "\nPrinting min heap in array form:" << endl;
            obj.printArray();
            cout << "Press any key to continue...\n";
            getch();
            cout << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "\nEnter proper option number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}