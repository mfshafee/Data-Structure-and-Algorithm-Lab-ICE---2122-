#include<bits/stdc++.h>
using namespace std;
class Stack{
     
    public:
    int *arr;
    int Top;
    int Size;
    int cnt;

    Stack(int Size){
        this->Size = Size;
        arr = new int[Size];
        Top = -1;
        cnt = 0;
    }

    void push(int element){
        if (Size - Top > 1)  
        {
            Top++;
            arr[Top] = element;
            cnt++;
        }
        else
            cout << "Stack Overflow!\n";  
        
    }

    void pop(){
        if (Top >= 0){
        Top--; cnt--;
    }
        else cout << "Stack Underflow!\n"; 
    }

    int top(){
        if (Top >= 0 && Top < Size)
        return arr[Top];
        else
        {
            cout << "Stack Empty.\n";
            return -1;
        }
        
    }

    bool empty(){
        if (Top == -1) return true;
        else return false;
    }

    int size(){
        return cnt;
    }
};
int main(){
    int n, maxweight;
    cout << "Enter the number of containers and maximum weight: ";
    cin >> n >> maxweight;
    
    int containers[n];
    Stack weights(n);

    int totalweight = 0;

    cout << "Enter weights: ";

    for (int i = 0; i < n; i++)
    {
        cin >> containers[i];
        totalweight += containers[i];
        weights.push(containers[i]);
    }

    if (totalweight > maxweight)
    {
        while (totalweight > maxweight)
        {
            totalweight -= weights.top();
            weights.pop();
        }
        
    }
        cout << "Stack Size: " << weights.size() << '\n';
        cout << "Total Weight: " << totalweight << '\n';
    return 0;
}