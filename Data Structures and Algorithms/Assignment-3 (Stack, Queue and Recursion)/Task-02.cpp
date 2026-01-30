#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int part(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        } 
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high){
    if (low < high)
    {
        int piv = part(arr, low, high);

        quicksort(arr, low, piv - 1);
        quicksort(arr, piv + 1, high);
    }
    
}
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}
int main(){
    int n;
    cout << "Enter Size: ";
    cin >> n;
    cout << "Enter elements: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Original array: ";
    print(arr, n);

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    print(arr, n);
    return 0;
}