#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    
    // Get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    // Get left child index
    int leftChild(int i) {
        return 2 * i + 1;
    }
    
    // Get right child index
    int rightChild(int i) {
        return 2 * i + 2;
    }
    
    // Heapify up - used after insertion
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    // Heapify down - used after deletion
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int n = heap.size();
        
        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    // Constructor to build heap from array
    MaxHeap(vector<int> arr) {
        heap = arr;
        int n = heap.size();
        
        // Build heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }
    
    // Insert a new element
    void insert(int value) {
        cout << "\n--- Insertion ---" << endl;
        cout << "Before insertion: ";
        display();
        
        // Add element at the end
        heap.push_back(value);
        
        // Heapify up from the last element
        heapifyUp(heap.size() - 1);
        
        cout << "After inserting " << value << ": ";
        display();
    }
    
    // Delete the root (maximum element)
    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        cout << "\n--- Deletion of Root ---" << endl;
        cout << "Before deletion: ";
        display();
        
        int deletedValue = heap[0];
        
        // Move last element to root
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        
        // Heapify down from root
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        cout << "After deleting root (" << deletedValue << "): ";
        display();
    }
    
    // Display the heap
    void display() {
        cout << "[";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i < heap.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    // Display heap as a tree (simple visualization)
    void displayTree() {
        cout << "\nTree structure (level-wise):" << endl;
        int level = 0;
        int levelSize = 1;
        int index = 0;
        
        while (index < heap.size()) {
            cout << "Level " << level << ": ";
            for (int i = 0; i < levelSize && index < heap.size(); i++) {
                cout << heap[index++] << " ";
            }
            cout << endl;
            level++;
            levelSize *= 2;
        }
    }
};

int main() {
    int n;
    vector<int> arr;
    
    cout << "Enter the number of elements in initial heap: ";
    cin >> n;
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr.push_back(value);
    }
    
    // Create Max Heap
    MaxHeap maxHeap(arr);
    
    cout << "\nInitial Max Heap: ";
    maxHeap.display();
    maxHeap.displayTree();
    
    // Insert operation
    int insertValue;
    cout << "\nEnter a value to insert: ";
    cin >> insertValue;
    maxHeap.insert(insertValue);
    maxHeap.displayTree();
    
    // Delete operation
    char choice;
    cout << "\nDo you want to delete the root? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        maxHeap.deleteRoot();
        maxHeap.displayTree();
    }
    
    return 0;
}