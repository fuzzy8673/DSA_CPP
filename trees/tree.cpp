
#include <iostream>
#include <string>
using namespace std;

class Binary_Tree {
private:
    // Structure of a tree node
    struct Node {
        int value;
        Node* left;
        Node* right;

        // Constructor
        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    // Recursively create the left and right children
    void populate(Node* node) {
        bool choice;

        // Create the left child
        cout << "Do you want to insert at the left of "
             << node->value << "? (1 for Yes, 0 for No): ";
        cin >> choice;

        if (choice) {
            int val;
            cout << "Enter the value of left of "
                 << node->value << ": ";
            cin >> val;

            node->left = new Node(val);
            populate(node->left);
        }

        // Create the right child
        cout << "Do you want to insert at the right of "
             << node->value << "? (1 for Yes, 0 for No): ";
        cin >> choice;

        if (choice) {
            int val;
            cout << "Enter the value of right of "
                 << node->value << ": ";
            cin >> val;

            node->right = new Node(val);
            populate(node->right);
        }
    }

    // Recursively display the tree
    void display(Node* node, string indent) {
        if (node == nullptr) {
            return;
        }

        // Print the current node
        cout << indent << node->value << endl;

        // Display left and right subtrees
        display(node->left, indent + "\t");
        display(node->right, indent + "\t");
    }

public:
    // Constructor
    Binary_Tree() {
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

    // Start displaying the tree
    void display() {
        display(root, "");
    }
};

int main() {
    Binary_Tree bt;

    bt.populate();
    cout << "\nBinary Tree:\n";
    bt.display();

    return 0;
}
