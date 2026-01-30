#include<bits/stdc++.h>
using namespace std;

// Linear Search
void linearsearch(vector<int> arr, int val){
    int n = arr.size();
    int found = 0, index;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val){ 
            found = 1;
            index = i;
        }
    }
    if (!found) cout << "Not found.\n";
    else cout << "Found at index: " << index << '\n';
}

// Print Array
void print(vector<int> arr){

    for (auto x: arr) cout << x << " ";
    cout << '\n';
}

// Bubble Sort
void bubblesort(vector<int> &arr){
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    
}

// Binary Search, it needs a sorted array. So, Bubble Sort first.
int binarysearch(vector<int> &arr, int val){
    bubblesort(arr);
     int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high)
    {
       
        int mid = low + (high - low) / 2;

        if (arr[mid] == val) return mid;

        if (arr[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // If not found
}

// Main
int main(){
    vector<int> a;
    int n;
    cout << "Enter 15 random integers (1-100): ";
    for (int i = 1; i <= 15; i++)
    {
        cin >> n;
        a.push_back(n);
    }
    vector<int> uns = a; // Make a copy of the unsorted input array
    while (1)            // In favor of Linear Search
    {
        int choice; 
        cout << "\n1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Exit\n";
        cout << "Choose any: ";
        cin >> choice;
        switch (choice)
        {
        case 1:{
            int val; 
            cout << "Enter a value: "; 
            cin >> val;
            linearsearch(uns, val); // Passing unsorted uns array
            break;
        }
        case 2:{
            int val; 
            cout << "Enter a value: "; 
            cin >> val;
            int result = binarysearch(a, val);
            if (result == -1) cout << "Not found\n";
            else cout << "Element is found at index " << result << '\n';
            break;
        }
        case 3:{
            cout << "Original array: "; print(a);
            bubblesort(a);
            cout << "Sorted array: ";
            print(a);
            break;
        }
        case 4:{
            break;
        }
        default:{
            cout << "Invalid choice, try again.\n";
            break;
        }
        }

        if (choice == 4) break;
    }
    return 0;
}