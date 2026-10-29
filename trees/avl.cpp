
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class AVL {
private:
    // Structure of a node
    struct Node {
        int value;
        Node* left;
        Node* right;
        int height;

        // Constructor
        Node(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
            height = 0;
        }
    };

    Node* root;

    // Return the height of a node
    // An empty tree has height -1
    int getHeight(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

    // Calculate balance factor
    // Balance factor = left height - right height
    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return getHeight(node->left) -
               getHeight(node->right);
    }

    // Right rotation
    Node* rightRotate(Node* p) {
        Node* c = p->left;
        Node* t = c->right;

        // Perform rotation
        c->right = p;
        p->left = t;

        // Update heights: child first, then new root
        p->height = 1 + max(getHeight(p->left),
                            getHeight(p->right));

        c->height = 1 + max(getHeight(c->left),
                            getHeight(c->right));

        return c;
    }

    // Left rotation
    Node* leftRotate(Node* c) {
        Node* p = c->right;
        Node* t = p->left;

        // Perform rotation
        p->left = c;
        c->right = t;

        // Update heights: old root first, then new root
        c->height = 1 + max(getHeight(c->left),
                            getHeight(c->right));

        p->height = 1 + max(getHeight(p->left),
                            getHeight(p->right));

        return p;
    }

    // Balance the tree if necessary
    Node* rotate(Node* node) {
        int balance = getBalance(node);

        // Left-heavy tree
        if (balance > 1) {

            // LL case
            if (getBalance(node->left) >= 0) {
                return rightRotate(node);
            }

            // LR case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right-heavy tree
        if (balance < -1) {

            // RR case
            if (getBalance(node->right) <= 0) {
                return leftRotate(node);
            }

            // RL case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Already balanced
        return node;
    }

    // Recursive insertion
    Node* insert(Node* node, int val) {
        // Step 1: Insert like a normal BST
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->value) {
            node->left = insert(node->left, val);
        }
        else if (val > node->value) {
            node->right = insert(node->right, val);
        }
        else {
            return node;  // Ignore duplicate values
        }

        // Step 2: Update height
        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        // Step 3: Balance the tree
        return rotate(node);
    }

    // Display the tree
    void display(Node* node, string details) {
        if (node == nullptr) {
            return;
        }

        cout << details << node->value
             << " (height = " << node->height << ")\n";

        display(node->left,
                "Left child of " + to_string(node->value) + ": ");

        display(node->right,
                "Right child of " + to_string(node->value) + ": ");
    }

    // Check whether the entire tree is balanced
    bool balanced(Node* node) {
        if (node == nullptr) {
            return true;
        }

        int balance = getBalance(node);

        return abs(balance) <= 1 &&
               balanced(node->left) &&
               balanced(node->right);
    }

public:
    // Constructor
    AVL() {
        root = nullptr;
    }

    // Public insertion function
    void insert(int val) {
        root = insert(root, val);
    }

    // Display the tree
    void display() {
        display(root, "Root node: ");
    }

    // Check whether the tree is balanced
    bool balanced() {
        return balanced(root);
    }

    // Return the height of the whole tree
    int getTreeHeight() {
        return getHeight(root);
    }
};

int main() {
    AVL tree;

    // Insert values into the AVL tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Display the final tree
    cout << "AVL Tree:\n";
    tree.display();

    cout << "\nTree height: "
         << tree.getTreeHeight() << endl;

    if (tree.balanced()) {
        cout << "The tree is balanced.\n";
    }
    else {
        cout << "The tree is not balanced.\n";
    }

    return 0;
}
