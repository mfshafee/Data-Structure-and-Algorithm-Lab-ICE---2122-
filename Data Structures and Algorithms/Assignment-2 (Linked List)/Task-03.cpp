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
    temp->next = newnode;
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

// Copy a linked list
Node* copyList(Node* head){
    if (head == NULL) return NULL;
    
    Node* newHead = NULL;
    Node* temp = head;
    
    while (temp != NULL)
    {
        append(newHead, temp->value);
        temp = temp->next;
    }
    
    return newHead;
}

// Remove duplicate elements (without sorting)
void removeDuplicates(Node* head){
    if (head == NULL) return;
    
    Node* copyHead = copyList(head);
    
    Node* current = copyHead;
    while (current != NULL)
    {
        Node* temp = current;
        while (temp->next != NULL)
        {
            if (temp->next->value == current->value)
            {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                duplicate->next = NULL;
                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }
    
    cout << "List after removing duplicates: ";
    display(copyHead);
    delete copyHead;
}

// Find the middle element of a linked list
void findMiddle(Node* head){
    if (head == NULL){
        cout << "List is empty.\n";
        return;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "Middle element: " << slow->value << '\n';
}

// Rearrange list: even elements before odd ones
void rearrangeEvenOdd(Node* head){
    if (head == NULL) return;
    
    Node* copyHead = copyList(head);
    
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* temp = copyHead;
    
    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        temp->next = NULL;
        
        if (temp->value % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        temp = nextNode;
    }
    
    Node* resultHead = NULL;
    
    if (evenHead == NULL)
    {
        resultHead = oddHead;
    }
    else if (oddHead == NULL)
    {
        resultHead = evenHead;
    }
    else
    {
        evenTail->next = oddHead;
        resultHead = evenHead;
    }
    
    cout << "List rearranged (even before odd): ";
    display(resultHead);
    delete resultHead;
}

// Reorder list in pattern: A0 → An → A1 → An-1 → ...
void reorderList(Node* head){
    if (head == NULL || head->next == NULL){
        cout << "List reordered: ";
        display(head);
        return;
    }
    
    Node* copyHead = copyList(head);
    
    // Find middle
    Node* slow = copyHead;
    Node* fast = copyHead;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node* prev = NULL;
    Node* curr = slow->next;
    slow->next = NULL;
    
    while (curr != NULL)
    {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    // Merge two halves
    Node* first = copyHead;
    Node* second = prev;
    
    while (second != NULL)
    {
        Node* temp1 = first->next;
        Node* temp2 = second->next;
        
        first->next = second;
        second->next = temp1;
        
        first = temp1;
        second = temp2;
    }
    
    cout << "List reordered: ";
    display(copyHead);
    delete copyHead;
}

// Main
int main(){
    Node* head = NULL;
    
    while (1)
    {
        cout << "\n1. Add elements\n";
        cout << "2. Display List\n";
        cout << "3. Remove duplicates\n";
        cout << "4. Find middle element\n";
        cout << "5. Rearrange (even before odd)\n";
        cout << "6. Reorder list\n";
        cout << "7. Exit\n";
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
            removeDuplicates(head);
            break;
        case 4:
            findMiddle(head);
            break;
        case 5:
            rearrangeEvenOdd(head);
            break;
        case 6:
            reorderList(head);
            break;
        case 7:
            break;                    
        default:
            cout << "Invalid choice, try again.\n";
            break;
        }

        if (choice == 7) break;
    }
    
    return 0;
}