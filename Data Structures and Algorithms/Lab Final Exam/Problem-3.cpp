#include<iostream>
using namespace std;
void TowerofHanoi(int n, char src, char des, char mid){
    if (n == 1)
    {
        cout << "Move peg-1 from " << src << " to " << des << '\n';
        return;
    }

    TowerofHanoi(n - 1, src, mid, des);
    cout << "Move peg-" << n << " from " << src << " to " << des << '\n';
    TowerofHanoi(n - 1, mid, des, src);
    
}
int main(){
    int n;
    cout << "Enter the number of pegs: ";
    cin >> n;
    TowerofHanoi(n, 'A', 'C', 'B');
    return 0;
}