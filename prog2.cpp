// start
//  Sorting and searching algorithms
#include <iostream>
#include <vector>

using namespace std;

// create a class for searching algorithm
class searchingAlgorithms
{
public:
    // create function for binarysearch
    int binarySearch(vector<int> &arr, int element) // initialize vector
    {
        int left = 0, right = arr.size() - 1, found = -1; // declare variable to be use
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // find mid of array
            if (arr[mid] == element)             // if arr[mid] is equal to element
            {
                found = mid; // store the value of mid in found
                break;
            }
            else if (arr[mid] < element) // else if check arr[mid] is smaller then element
            {
                left = mid + 1; // then define left
            }
            else // else define right
            {
                right = mid - 1;
            }
        }

        if (found != -1)                                         // if found is not equal to -1
            cout << "Element found at index: " << found << endl; // then display where the element is found
        else
            cout << "Element not found." << endl; // if not display element not found
        return found;
    }
};

// creat class for sorting algorithms
class sortingAlgorithms
{
public:
    // creat a function for merge sort
    void mergeSorting(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> temp;
        int i = start, j = mid + 1; // declare variable

        while (i <= mid && j <= end) // use while loop according to neccesity
        {
            if (arr[i] < arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= mid)
        {
            temp.push_back(arr[i++]);
        }
        while (j <= end)
        {
            temp.push_back(arr[j++]);
        }
        for (int k = 0; k < temp.size(); k++)
        {
            arr[start + k] = temp[k];
        }
    }

    // create another merge sort function to rearrange the array
    void mergeSort(vector<int> &arr, int start, int end)
    {
        if (start >= end)
            return;
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid); // call functions
        mergeSort(arr, mid + 1, end);
        mergeSorting(arr, start, mid, end);
    }

    // create an function for quick sort
    void quickSort(vector<int> &arr, int low, int high) // initialize vector
    {
        if (low < high) // check if condition
        {
            int pi = partition(arr, low, high); // according to which perform tasks
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // create partition function to devide the array
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high]; // declare variales
        int i = low - 1;
        for (int j = low; j < high; ++j) // run for loop
        {
            if (arr[j] < pivot) // and check the condition
            {
                i++;
                swap(arr[i], arr[j]); // acording to which switch the value
            }
        }
        swap(arr[i + 1], arr[high]); // again swap the value to sort the arr
        return i + 1;                // return i+1 to show the partition
    }

    // function to check the rray is sorted or not
    bool sortcheck(vector<int> &arr, int n)
    {
        for (int i = 1; i < n; i++) // run the for loop
        {
            if (arr[i] < arr[i - 1]) // if the condition matchs
            {
                return false; // return false
            }
        }
        return true; // else return true
    }
};

// create a class to display the array inherit with both the previous classes
class display : public searchingAlgorithms, public sortingAlgorithms
{
public:
    void displayArray(const vector<int> &arr)
    {
        cout << "Array: ";
        for (int i = 0; i < arr.size(); i++)
        { // use for loop to display the array
            cout << arr[i] << " ";
        }
    }
};
// start main function
int main()
{
    display obj;                   // create obj for class
    vector<int> arr;               // declare vector
    int n, choice, element, index; // declare other variables

    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter " << i << " element of an array : ";
        cin >> arr[i];
    }

    // create do while loop
    do
    {
        // menu to run the function
        cout << "\nMenu:\n";
        cout << "1. Merge Sort\n";
        cout << "2. Quick Sort\n";
        cout << "3. Binary Search\n";
        cout << "4. Check if array is Sorted\n";
        cout << "5. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // start switch case to run the menu driven program according to user
        switch (choice)
        {
        case 1: // calling merge sort
            obj.mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort.\n";
            break;
        case 2:
            obj.quickSort(arr, 0, n - 1); // calling quick sort
            cout << "Array sorted using Quick Sort.\n";
            break;
        case 3:
            cout << "Enter element to search: "; // calling binary search
            cin >> element;
            if (!obj.sortcheck(arr, n))
            {
                cout << "Binary search Requires sorted Array\n"; // calling sortcheck to check aaray is empty or not
            }
            else
            {
                obj.binarySearch(arr, element);
            }
            break;
        case 4:
            if (obj.sortcheck(arr, n)) // calling shortcheck
                cout << "Array is sorted.\n";
            else
                cout << "Array is not sorted.\n";
            break;
        case 5:
            obj.displayArray(arr);
            break; // calling displayarray
        case 0:
            cout << "Exiting...\n"; // exiting the program
            break;
        default:
            cout << "Invalid choice. Try again.\n"; // default invalid choice
        }
    } while (choice != 0);
    return 0; // return statement
}
// end