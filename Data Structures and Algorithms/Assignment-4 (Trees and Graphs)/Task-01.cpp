#include <iostream>
#include <queue>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;
    
    // Helper function to insert a node
    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value <= node->data) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }
    
    // Helper function for pre-order traversal
    void preOrderHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
    
    // Helper function for in-order traversal
    void inOrderHelper(Node* node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }
    
    // Helper function for post-order traversal
    void postOrderHelper(Node* node) {
        if (node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }
    
    // Helper function to search for a key
    bool searchHelper(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        
        if (key < node->data) {
            return searchHelper(node->left, key);
        } else {
            return searchHelper(node->right, key);
        }
    }
    
    // Helper function to calculate path length
    int pathLengthHelper(Node* node, int level) {
        if (node == nullptr) return 0;
        return level + pathLengthHelper(node->left, level + 1) + pathLengthHelper(node->right, level + 1);
    }
    
public:
    BinarySearchTree() {
        root = nullptr;
    }
    
    // Insert a value into the BST
    void insert(int value) {
        root = insertHelper(root, value);
    }
    
    // Pre-order traversal
    void preOrder() {
        cout << "Pre-order: ";
        preOrderHelper(root);
        cout << endl;
    }
    
    // In-order traversal
    void inOrder() {
        cout << "In-order: ";
        inOrderHelper(root);
        cout << endl;
    }
    
    // Post-order traversal
    void postOrder() {
        cout << "Post-order: ";
        postOrderHelper(root);
        cout << endl;
    }
    
    // Search for a key
    void search(int key) {
        if (searchHelper(root, key)) {
            cout << "Search for " << key << ": Yes" << '\n';
        } else {
            cout << "Search for " << key << ": No" << '\n';
        }
    }
    
    // Calculate path length
    void pathLength() {
        int length = pathLengthHelper(root, 0);
        cout << "Path length of the tree: " << length << '\n';
    }
};

int main() {
    BinarySearchTree bst;
    int n, value;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    cout << "Enter " << n << " values to insert into BST:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.insert(value);
    }
    
    cout << "\n--- Tree Traversals ---\n";
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();
    
    cout << "\n--- Search Operation ---\n";
    cout << "Enter a key to search: ";
    cin >> value;
    bst.search(value);
    
    cout << "\n--- Insert Operation ---\n";
    cout << "Enter a value to insert: ";
    cin >> value;
    bst.insert(value);
    cout << "After inserting " << value << ":\n";
    bst.inOrder();
    
    cout << "\n--- Path Length ---\n";
    bst.pathLength();
    
    return 0;
}