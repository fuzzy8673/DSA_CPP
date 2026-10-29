
#include <iostream>
using namespace std;

// Structure of a tree node
struct Node {
    int value;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    // Recursively create the tree
    void populate(Node* node) {
        int choice, val;

        // Create the left child
        cout << "Do you want to insert at the left of "
             << node->value << "? (1 = Yes, 0 = No): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the value of left of "
                 << node->value << ": ";
            cin >> val;

            node->left = new Node(val);

            // Create children of the new left node
            populate(node->left);
        }

        // Create the right child
        cout << "Do you want to insert at the right of "
             << node->value << "? (1 = Yes, 0 = No): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the value of right of "
                 << node->value << ": ";
            cin >> val;

            node->right = new Node(val);

            // Create children of the new right node
            populate(node->right);
        }
    }

    // Display the tree
    void display(Node* node, int level) {
        if (node == nullptr) {
            return;
        }

        // Print indentation according to the level
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }

        cout << node->value << endl;

        // Display left and right subtrees
        display(node->left, level + 1);
        display(node->right, level + 1);
    }

    // Inorder traversal: Left, Root, Right
    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    // Preorder traversal: Root, Left, Right
    void preorder(Node* node) {
        if (node == nullptr) return;

        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder traversal: Left, Right, Root
    void postorder(Node* node) {
        if (node == nullptr) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->value << +" ";
    }

public:
    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Start creating the tree
    void populate() {
        int val;

        cout << "Enter the root node: ";
        cin >> val;

        root = new Node(val);
        populate(root);
    }

    // Display the tree structure
    void display() {
        display(root, 0);
    }

    // Start traversals
    void traversals() {
        cout << "\nInorder: ";
        inorder(root);

        cout << "\nPreorder: ";
        preorder(root);

        cout << "\nPostorder: ";
        postorder(root);

        cout << endl;
    }
};

int main() {
    BinaryTree bt;

    bt.populate();

    cout << "\nBinary Tree:\n";
    bt.display();

    bt.traversals();

    return 0;
}
