#include<bits/stdc++.h>
using namespace std;

// Reverse array
void reversearr(vector<int> &arr){
    
    //reverse(arr.begin(), arr.end()); // Directly reverse

    int size = arr.size();
    for (int i = 0; i < size / 2; i++)
    {
        //swap(arr[i], arr[size - 1 - i]);  // Using swap() function

        // Swapping elements using third variable
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;

    }
    
}

// Count how many elements are even and how many are odd
void countevenodd(vector<int> arr){
    int odd = 0, even = 0;
    for (auto x: arr){
        if (x % 2 == 0) even++;
        else odd++;
    }
    cout << "Even numbers: " << even << '\n';
    cout << "Odd numbers: " << odd << '\n';
}

// Find the 2nd largest element in the array
void find2ndlargest(vector<int> &arr){
    int s = arr.size();
    if (s < 2){   // If array size is less than two...
        cout << "Second largest element doesn't exist.\n";
        return;
    }

    int max = INT_MIN, secmax = INT_MIN; // INT_MIN for all possible integers, even negative ones.
    for (int i = 0; i < s; i++)
    {
        if (arr[i] > max)  // If any element is greater than max,
        {                  // It would be the new largest and the previous will be the 2nd largest.
            secmax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > secmax)  // If any element is less than max, but greater than secmax,
        {                                          // It becomes the 2nd largest element.
            secmax = arr[i];            
        }
        
    }

    if (secmax == INT_MIN) cout << "Second largest element doesn't exist.\n";
    else cout << "Second largest element: " << secmax << '\n';
    
}

// Print array
void print(vector<int> arr){
    for(auto x: arr){
        cout << x << " ";
    }
    cout << '\n';
}

// Main
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements (Integers): ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Original array: ";
    print(a);
    while (1)
    {
        int choice;
        cout << "\n1. Reverse array\n";
        cout << "2. Count odds and evens\n";
        cout << "3. Find the second largest\n";
        cout << "4. Exit\n";
        cout << "Choose any: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            reversearr(a);
            cout << "Reversed array: ";
            print(a);
            break;
        case 2:
            countevenodd(a);
            break;
        case 3:
            find2ndlargest(a);
            break;
            case 4:
            
            break;            
        default:
        cout << "Invalid choice, try again.\n";
            break;
        }

        if (choice == 4) break;
    }
    
    return 0;
}