#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DualList{
    private:
    Node* head;  // For queue front / stack bottom direction
    Node* tail;  // For queue rear / stack top direction
    bool isStackMode;  // true = stack, false = queue

    public:
    // Constructor
    DualList(){
        head = NULL;
        tail = NULL;
        isStackMode = true;
    }

    // Destructor
    ~DualList(){
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
    }
    // Display list
    void display(){
        if (head == NULL){
            cout << '\n';
            return;
        }

        if (isStackMode){
            // Stack mode: print from tail to head (Top -> bottom)
            Node* curr = tail;
            while (curr)
            {
                cout << curr->data;
                if (curr->prev) cout << " ";
                curr = curr->prev;
            }
            
        }

        else
        {
            // Queue mode: print from head to tail (Front -> rear)
            Node* curr = head;
            while (curr)
            {
                cout << curr->data;
                if (curr->next) cout << " ";
                curr = curr->next;
            }
            
        }
        cout << '\n';
    }
    // Switch to stack
    void switchtoStack(){
        isStackMode = true;
        display();
    }
    // Switch to queue
    void switchtoQueue(){
        isStackMode = false;
        display();
    }
    // Insert value
    void insert(int value){
        Node* newNode = new Node{value, NULL, NULL};
        if(tail == NULL)
        head = tail = newNode;
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Remove value
    void remove(){
        // Check for Underflow
        if (head == NULL){
            cout << "EMPTY\n";
            return;
        }

        if(isStackMode){
            // Pop from tail (Stack top)
            int value = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            if (tail) tail->next = NULL;
            else head = NULL;       // List is now empty
            delete temp;
            cout << value << '\n';
        }
        else
        {
            // Dequeue from head (queue front)
            int value = head->data;
            Node* temp = head;
            head = head->next;
            if (head) head->prev = NULL;
            else tail = NULL;
            delete temp;
            cout << value << '\n';
        }
        
    }

};

int main(){
    DualList list;
    string com;
    while (cin >> com)
    {
        if (com == "Q") break;
        else if(com == "s") list.switchtoStack();
        else if(com == "q") list.switchtoQueue();
        else if(com == "p") list.remove();
        else
        {
            int value = stoi(com);
            list.insert(value);
        }
        
    }
    return 0;
}