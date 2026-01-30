#include<bits/stdc++.h>
using namespace std;

// Replacing all negative numbers with 0
void replacenegatives(vector<int> &arr){
    for (int &x : arr){
        if (x < 0) x = 0;
    }
}

// Multiplying even numbers by 2
void multiplyevens(vector<int> &arr){
    for (int &x : arr){
        if (x % 2 == 0) 
        x *= 2;
    }
}

// Creating new array with unique elements
vector<int> unqels(vector<int> &arr){
    vector<int> unique;
    for (int x : arr){
        bool found = false;
        for (int y : unique){
            if (x == y){
                found = true;
                break;
            }
        }
        if (!found) unique.push_back(x);
    }
    return unique;
}

// Main
int main(){
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    replacenegatives(a);
    multiplyevens(a);

    vector<int> uniqueelements = unqels(a);

    cout << "Array for Unique elements: ";
    for (int x : uniqueelements)
    cout << x << " ";
    return 0;
}