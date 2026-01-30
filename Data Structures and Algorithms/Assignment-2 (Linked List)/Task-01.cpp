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
        // Free memory
        if (this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

// Insert at begining
void inserthead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

// Insert at end
void inserttail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

// Insert at a specific position
void insertanyposition(Node* &head, Node* &tail, int pos, int val){
    if (pos == 1){
        inserthead(head, val);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL){
        inserttail(tail, val);
        return;
    }
    Node* toadd = new Node(val);
    toadd->next = temp->next;
    temp->next = toadd;

}

// Delete at begining, end or any position by nodes
void deletenodes(Node* &head, Node* &tail, int pos){
    if (head == NULL){
        cout << "Underflow\n";
        return;
    }
     if (pos == 1){
        Node* temp = head; 
        head = head->next; // 2nd node becomes head
        // Free memory of starting node
        temp->next = NULL; // temp(head) -> NULL
        delete temp;
        if (head == NULL) {
            tail = NULL;          // Update tail
        }
    }
    else{
        // Deleting last or middle nodes
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next; // prev -> curr -> nextcurr
        curr->next = NULL;       // curr -> NULL
        delete curr;             // prev -> nextcurr and curr gets deleted
        if (prev->next == NULL) {
            tail = prev;            // Update tail
        }
    }
}

// Delete by value
void deleteval(Node* &head, Node* &tail, int val){
    if (head == NULL) {
        cout << "Underflow!\n";
        return; // List is empty
    }
    
    Node* curr = head;
    Node* prev = NULL;
    
    // Traverse to find the node with value val
    while (curr != NULL && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        cout << "Not found\n";
        return; // Value not found
    }
    
    // If the node to delete is the head
    if (prev == NULL) {
        head = head->next;
        curr->next = NULL;
        delete curr;
        if (head == NULL) {
            tail = NULL;        // Update tail
        }
    } else {
        // Node is in the middle or end
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if (prev->next == NULL) {
            tail = prev;            // Update tail
        }
    }
}

// Print and count the nodes
void printlist(Node* &head){
    Node* temp = head;
    int cnt = 0;
    cout << "List elements: ";
    while (temp != NULL)
    {
        cout << temp->value << " ";
        cnt++;
        temp = temp->next;
    }
    cout << '\n';
    cout << "Number of nodes: " << cnt << '\n';
}

// Main
int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    

    printlist(head);
    inserthead(head, 0);
    printlist(head);
    inserttail(tail, 2);
    printlist(head);
    insertanyposition(head, tail, 2, 5);
    printlist(head);
    insertanyposition(head, tail, 4, 10);
    printlist(head);
    insertanyposition(head, tail, 6, 20);
    printlist(head);
    deletenodes(head, tail, 6);
    printlist(head);
    deleteval(head, tail, 5);
    printlist(head);
    
    return 0;
}