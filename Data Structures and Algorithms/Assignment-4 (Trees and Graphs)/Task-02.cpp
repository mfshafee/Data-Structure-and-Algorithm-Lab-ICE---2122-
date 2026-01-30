#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMaxHeap;
    
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
    
    // Heapify down for maintaining heap property
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int n = heap.size();
        
        if (isMaxHeap) {
            // Max Heap
            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;
        } else {
            // Min Heap
            if (left < n && heap[left] < heap[largest])
                largest = left;
            if (right < n && heap[right] < heap[largest])
                largest = right;
        }
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    Heap(bool maxHeap = true) {
        isMaxHeap = maxHeap;
    }
    
    // Build heap from an array
    void buildHeap(vector<int> arr) {
        heap = arr;
        int n = heap.size();
        
        // Start from the last non-leaf node and heapify down
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
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
    
    // Get heap type
    string getType() {
        return isMaxHeap ? "Max Heap" : "Min Heap";
    }
};

int main() {
    int n;
    vector<int> arr;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr.push_back(value);
    }
    
    cout << "\nInput array: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\n\n";
    
    // Create Max Heap
    Heap maxHeap(true);
    maxHeap.buildHeap(arr);
    cout << "Max Heap: ";
    maxHeap.display();
    
    // Create Min Heap
    Heap minHeap(false);
    minHeap.buildHeap(arr);
    cout << "Min Heap: ";
    minHeap.display();
    
    return 0;
}