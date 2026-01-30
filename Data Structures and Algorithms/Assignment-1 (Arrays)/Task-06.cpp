#include<bits/stdc++.h>
using namespace std;

// Merge arrays
vector<int> merge(vector<int> &a, vector<int> &b){
    vector<int> merged = a;
    for (int x : b){
        merged.push_back(x);
    }
    return merged;
}

// Find common elements from the arrays
vector<int> cmnels(vector<int> &a, vector<int> &b){
    vector<int> common;

    for (int x: a){
        for (int y: b){
            if (x == y){
                common.push_back(x);
                break;
            }
        }
    }
    return common;
}

// Find unique elements from the arrays
vector<int> one(vector<int> &a, vector<int> &b){
    vector<int> oneee;

    // Element is in a but not in b
    for (int x: a){
        bool found = false;
        for (int y: b){
            if (x == y){
                found = true;
                break;
            }
        }
        if (!found) oneee.push_back(x);
    }


    // Element is in b but not in a
    for (int x: b){
        bool found = false;
        for (int y: a){
            if (x == y){
                found = true;
                break;
            }
        }
        if (!found) oneee.push_back(x);
    }

    return oneee;
}

// Main
int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> a(n), b(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    cin >> a[i];
    for (int i = 0; i < n; i++)
    cin >> b[i];

    vector<int> mergedarr = merge(a, b);
    vector<int> commonels = cmnels(a, b);
    vector<int> uniqueels = one(a, b);

    cout << "Merged: ";
    for (int x: mergedarr)
    cout << x << ' ';

    cout << "\nCommon: ";
    for (int x: commonels)
    cout << x << ' ';


    cout << "\nOnly in one array: ";
    for (int x: uniqueels)
    cout << x << ' ';
   
    return 0;
}