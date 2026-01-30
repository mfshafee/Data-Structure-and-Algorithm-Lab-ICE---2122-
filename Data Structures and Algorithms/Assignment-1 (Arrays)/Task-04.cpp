// 3x3 Matrix
#include<bits/stdc++.h>
using namespace std;

// Display matrix
void print(int arr[3][3]){
    cout << "Output matrix: \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << "\n";
    }
    
}

// Sum of each row and each column
void sumofrowsandcols(int arr[3][3]){
    // Sum of each row
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        
        cout << "Sum of row-" << i + 1 << ": " << sum << '\n';
    }
    
    // Sum of each column
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[j][i];
        }
        
        cout << "Sum of column-" << i + 1 << ": " << sum << '\n';
    }
}

// Sums of main diagonal and second diagonal
void sumofdiagonals(int arr[3][3]){
    int mdsum = 0;
    int sdsum = 0;
    for (int i = 0; i < 3; i++)
    {
        mdsum += arr[i][i];
        sdsum += arr[i][2 - i];
    }
    cout << "Sum of main diagonal: " << mdsum << '\n';
    cout << "Sum of secondary diagonal: " << sdsum << '\n';
}

// Main
int main(){
    int arr[3][3];
    cout << "Enter matrix elements: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
        
    }

    while (true)
    {
        int choice;
        cout << "\n1. Display matrix\n";
        cout << "2. Sum of each row and column\n";
        cout << "3. Sum of main diagonal and secondary diagonal\n";
        cout << "4. Exit\n";
        cout << "Choose any: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            print(arr);
            break;
        case 2:
            sumofrowsandcols(arr);
            break;
        case 3:
            sumofdiagonals(arr);
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