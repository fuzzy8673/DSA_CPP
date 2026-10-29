
#include <iostream>
#include <algorithm> // For max()
#include <cmath>     // For abs()
using namespace std;

class BinarySearchTree
{

private:
    // Structure of one node of the tree
    class Node
    {
    public:
        int value;   // Data stored in the node
        Node *left;  // Pointer to the left child
        Node *right; // Pointer to the right child
        int height;  // Height of the node

        // Constructor: initializes a new node
        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
            height = 0;
        }
    };

    Node *root; // Points to the root node of the tree

public:
    // Constructor: initially, the tree is empty
    BinarySearchTree()
    {
        root = nullptr;
    }

    // Returns the height of a node
    int getHeight(Node *node)
    {
        // An empty subtree has height -1
        if (node == nullptr)
        {
            return -1;
        }

        return node->height;
    }

    // Checks whether the tree is empty
    bool isEmpty()
    {
        return root == nullptr;
    }

    // Displays the entire tree
    void display()
    {
        display(root, "Root node: ");
    }

private:
    // Displays a node and its children
    void display(Node *node, string details)
    {

        // Base case: nothing to display
        if (node == nullptr)
        {
            return;
        }

        cout << details << node->value << endl;

        // Display the left subtree
        display(node->left,
                "Left child of " + to_string(node->value) + ": ");

        // Display the right subtree
        display(node->right,
                "Right child of " + to_string(node->value) + ": ");
    }

public:
    // Public insert function
    void insert(int val)
    {
        root = insert(val, root);
    }

private:
    // Inserts a value into the correct position
    Node *insert(int val, Node *node)
    {

        // If the position is empty, create a new node
        if (node == nullptr)
        {
            node = new Node(val);
            return node;
        }

        // Smaller values go to the left subtree
        if (val < node->value)
        {
            node->left = insert(val, node->left);
        }

        // Larger values go to the right subtree
        else if (val > node->value)
        {
            node->right = insert(val, node->right);
        }

        // If val equals node->value, do not insert a duplicate

        // Update the height of the current node
        node->height = max(getHeight(node->left),
                           getHeight(node->right)) +
                       1;

        return node;
    }

public:
    // Checks whether the entire tree is balanced
    bool balanced()
    {
        return balanced(root);
    }

private:
    // Checks whether a subtree is balanced
    bool balanced(Node *node)
    {

        // An empty subtree is balanced
        if (node == nullptr)
        {
            return true;
        }

        // Calculate the difference between left and right heights
        int difference = abs(getHeight(node->left) - getHeight(node->right));

        // Current node and both subtrees must be balanced
        return difference <= 1 && balanced(node->left) && balanced(node->right);
    }

public:
    // Destructor: releases the memory used by the tree
    ~BinarySearchTree()
    {
        destroyTree(root);
    }

private:
    // Deletes all nodes recursively
    void destroyTree(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    // INORDER Traversal: Left -> Root -> Right
    public: 
    void inorder()
    {
        inorder(root);
        cout << endl;
    }

private:
    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return; // Stop if the node is empty
        }

        inorder(node->left);        // Visit left subtree
        cout << node->value << " "; // Print current node
        inorder(node->right);       // Visit right subtree
    }

public:
    // PREORDER Traversal: Root -> Left -> Right
    void preorder()
    {
        preorder(root);
        cout << endl;
    }

private:
    void preorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->value << " "; // Print current node first
        preorder(node->left);       // Visit left subtree
        preorder(node->right);      // Visit right subtree
    }

public:
    // POSTORDER Traversal: Left -> Right -> Root
    void postorder()
    {
        postorder(root);
        cout << endl;
    }

private:
    void postorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        postorder(node->left);      // Visit left subtree
        postorder(node->right);     // Visit right subtree
        cout << node->value << " "; // Print current node last
    }
};

int main()
{

    // Create a Binary Search Tree
    BinarySearchTree bst;

    // Values to be inserted
    // int arr[] = {15,18, 9, 17};

    // int n = sizeof(arr) / sizeof(arr[0]);

    // Insert every array element into the BST
    for (int i = 0; i < 1000; i++)
    {
        bst.insert(i);
    }
    // cout<<bst.getHeight(bst.root);

    // Display the tree
    bst.display();

    // Check whether the tree is empty
    // cout << "\nIs tree empty? "
    //      << (bst.isEmpty() ? "Yes" : "No") << endl;

    // // Check whether the tree is balanced
    // cout << "Is tree balanced? "
    //      << (bst.balanced() ? "Yes" : "No") << endl;

    // cout << "\nInorder Traversal: ";
    // bst.inorder();

    // cout << "Preorder Traversal: ";
    // bst.preorder();

    // cout << "Postorder Traversal: ";
    // bst.postorder();

    return 0;
}
