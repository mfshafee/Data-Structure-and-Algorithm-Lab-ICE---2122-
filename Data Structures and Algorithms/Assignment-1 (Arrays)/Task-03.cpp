#include<bits/stdc++.h>
using namespace std;

// To find median
double findmedian(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Requires sorted array
    if (n % 2 != 0) return arr[n / 2]; // n odd
    else return (arr[n / 2 - 1] + arr[n / 2]) / 2.0; // n even
}

// To find mode
int findmode(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Requires sorted array
    int mode = arr[0];   // Initialize mode to the first index

    // Initialize counters
    int maxcnt = 1;
    int curcnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1]) curcnt++;
        else curcnt = 1;

        if (curcnt > maxcnt){
            maxcnt = curcnt;
            mode = arr[i]; // Update mode
        }
    }
    if (maxcnt == 1) return -1; // No mode
    return mode;
}

// Print how many times each number occurs
void printnumcounts(vector<int> arr){
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1]) cnt++;
        else
        {
            cout << arr[i - 1] << " occurs " << cnt << " times\n";
            cnt = 1; // Initialize again
        }
        
    }
    cout << arr[n - 1] << " occurs " << cnt << " times\n"; // Prints the count of last element
}

// Count numbers greater than a given threshold
void greaterthanthreshold(vector<int> arr, int val){
    int cnt = 0;
    int n = arr.size();
    vector<int> x;     // To store the greater values
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > val){ 
            cnt++;
            x.push_back(arr[i]);
        }
    }
    cout << "There are " << cnt << " values greater than " << val << '\n';
    // To print the greater values...
    if (!cnt) return;
    else {
    cout << "Values: ";
    for (auto y: x) cout << y << " ";
    cout << '\n'; 
    }
}

// Main
int main(){
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> unsorted = v;
    while (1)
    {
        int choice;
        cout << "\n1. Count numbers greater than a threshold\n";
        cout << "2. Find median\n";
        cout << "3. Find mode\n";
        cout << "4. Print occurrences of each number\n";
        cout << "5. Exit\n";
        cout << "Choose any: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter a threshold: ";
            cin >> value;
            greaterthanthreshold(unsorted, value);
            break;
        case 2:
            {
                //vector<int> temp = unsorted;
                double median = findmedian(unsorted);
                cout << "Median = " << median << '\n';
            }
            break;
        case 3:
            {
               // vector<int> temp = unsorted;
                int mode = findmode(unsorted);
                if (mode == -1) cout << "No mode exists\n";
                else cout << "Mode = " << mode << '\n';
            }
            break;
        case 4:
            {
                printnumcounts(unsorted);
            }
            break;
        case 5:

            break;   
        default:
            cout << "Invalid choice, try again\n";
            break;
        }
        if (choice == 5)
            break;
    }
    return 0;
}