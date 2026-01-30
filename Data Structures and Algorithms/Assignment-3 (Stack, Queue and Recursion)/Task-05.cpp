// Program to illustrate how to implement Tower of Hanoi algorithm
#include<iostream>
using namespace std;

void towerofhanoi(int n, char src, char des, char aux){
    // If there's only one disk:
    if (n == 1)
    {
        // Print the move for the single disk
        cout << "Move disk 1 from rod " << src << " to rod " << des << '\n';
        return;
    }

    // To move n-1 disks from src to aux using des
    towerofhanoi(n - 1, src, aux, des);

    // Print the move for nth disks
    cout << "Move disk " << n << " from rod " << src << " to rod " << des << '\n';

    // To move n-1 disks form aux to des using src
    towerofhanoi(n - 1, aux, des, src);
}

int main(){
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}