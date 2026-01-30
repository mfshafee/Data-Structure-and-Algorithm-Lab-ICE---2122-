#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    //Constructor
    Node(int value){
        this->value = value;
        this->next = NULL;
    }

    //Destructor
    ~Node(){
        int value = this->value;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        
    }
};

// Insert at end 
void append(Node* &head, int val){
    Node* newnode = new Node(val);

    // Inserting in an empty list
    if (head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;   // .....temp -> newnode
}

// Display the list
void display(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << '\n';
}

// Linear Search
void linearsearch(Node* head, int k){
    Node* temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        if (temp->value == k)
        {
            cout << "Found at Node-" << cnt << '\n';
            return;
        }
        temp = temp->next;
        cnt++;
    }
    cout << "Not found\n";
}

// Print elements greater than a given input
void printgreater(Node* head, int k){
    Node* temp = head;
    cout << "Values greater than " << k << ": ";
    while (temp != NULL)
    {
        if (temp->value > k){
            cout << temp->value << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
    
}

// Print elements less than a given input
void printless(Node* head, int k){
    Node* temp = head;
    cout << "Values less than " << k << ": ";
    while (temp != NULL)
    {
        if (temp->value < k){
            cout << temp->value << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

// Reverse traversal (Using recursion)
void revdisplay(Node* head){
    if (head == NULL)
    return;

    revdisplay(head->next);  // Recursive function
    cout << head->value << " ";
}

// Find and display the maximum and minimum values
void findMaxMin(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    int maxVal = INT_MIN;  // Initialization
    int minVal = INT_MAX;  // Initialization

    Node* temp = head;
    while (temp != NULL) {
        if (temp->value > maxVal)
            maxVal = temp->value;
        if (temp->value < minVal)
            minVal = temp->value;
        temp = temp->next;
    }

    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;
}

// Main
int main(){
    Node* head = NULL;
    
    while (1)
    {
        cout << "\n1. Add elements\n";
        cout << "2. Display List\n";
        cout << "3. Linear Search\n";
        cout << "4. Display element greater than a number\n";
        cout << "5. Display element less than a number\n";
        cout << "6. Reverse Traversal\n";
        cout << "7. Display maximum and minimum values\n";
        cout << "8. Exit\n";
        cout << "Choose any: ";
        int choice; cin >> choice;
        switch (choice)
        {
        case 1:
            int n1;
            cout << "Enter value: ";
            cin >> n1;
            append(head, n1);
            break;
        case 2:
        cout << "List: ";
            display(head);
            break;
        case 3:
        int n2;
        cout << "Enter a value: ";
        cin >> n2;
            linearsearch(head, n2);
            break;
        case 4:
            int n3; 
            cout << "Enter a value: ";
            cin >> n3;
            printgreater(head, n3);
            break;
        case 5:
            int n4; 
            cout << "Enter a value: ";
            cin >> n4;
            printless(head, n4);
            break;
        case 6:
            cout << "Reversed List: ";
            revdisplay(head);
            break;
        case 7:
            findMaxMin(head);
            break;
        case 8:
            
            break;                    
        default:
        cout << "Invalid choice, try again.\n";
            break;
        }

        if (choice == 8) break;
    }
    
    return 0;
}


