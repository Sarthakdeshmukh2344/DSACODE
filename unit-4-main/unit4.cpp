
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for the BST and AVL tree
struct Node {
    int accountNumber;
    Node* left;
    Node* right;
    int height;

    Node(int acc) {
        accountNumber = acc;
        left = right = nullptr;
        height = 1;
    }
};

// Get height of a node
int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Update height
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Get balance factor
int getBalance(Node* node) {
    return (node == nullptr) ? 0 :
        getHeight(node->left) - getHeight(node->right);
}

// Insert into AVL tree
Node* insertAVL(Node* root, int accountNumber) {
    if (root == nullptr)
        return new Node(accountNumber);

    if (accountNumber < root->accountNumber)
        root->left = insertAVL(root->left, accountNumber);
    else if (accountNumber > root->accountNumber)
        root->right = insertAVL(root->right, accountNumber);
    else
        return root; // Ignore duplicate account numbers

    updateHeight(root);

    int balance = getBalance(root);

    // Left-Left case
    if (balance > 1 &&
        accountNumber < root->left->accountNumber)
        return rightRotate(root);

    // Right-Right case
    if (balance < -1 &&
        accountNumber > root->right->accountNumber)
        return leftRotate(root);

    // Left-Right case
    if (balance > 1 &&
        accountNumber > root->left->accountNumber) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left case
    if (balance < -1 &&
        accountNumber < root->right->accountNumber) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Store BST inorder traversal
void inorder(Node* root, vector<int>& accounts) {
    if (root == nullptr)
        return;

    inorder(root->left, accounts);
    accounts.push_back(root->accountNumber);
    inorder(root->right, accounts);
}

// Rebuild a balanced BST from sorted inorder sequence
Node* buildBalancedBST(vector<int>& accounts,
                       int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node* root = new Node(accounts[mid]);

    root->left = buildBalancedBST(accounts, start, mid - 1);
    root->right = buildBalancedBST(accounts, mid + 1, end);

    updateHeight(root);
    return root;
}

// Print inorder traversal
void printInorder(Node* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->accountNumber << " ";
    printInorder(root->right);
}

// Display tree structure
void displayTree(Node* root, int space = 0) {
    if (root == nullptr)
        return;

    space += 5;
    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->accountNumber;

    displayTree(root->left, space);
}

// Main function
int main() {
    Node* avlRoot = nullptr;
    vector<int> accounts;
    int n, accountNumber;

    cout << "BANK ACCOUNT INDEXING APPLICATION\n";
    cout << "Enter number of bank accounts: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of accounts.\n";
        return 0;
    }

    cout << "Enter account numbers:\n";

    for (int i = 0; i < n; i++) {
        cin >> accountNumber;

        // Construct AVL tree by insertion
        avlRoot = insertAVL(avlRoot, accountNumber);
    }

    // Extract sorted inorder sequence from AVL tree
    inorder(avlRoot, accounts);

    // Rebuild a balanced BST from inorder sequence
    Node* balancedRoot =
        buildBalancedBST(accounts, 0, (int)accounts.size() - 1);

    cout << "\nSorted account numbers: ";
    printInorder(avlRoot);

    cout << "\n\nBalanced BST structure:";
    displayTree(balancedRoot);

    cout << "\n\nAVL Tree structure:";
    displayTree(avlRoot);

    cout << "\n\nHeight of rebuilt balanced BST: "
         << getHeight(balancedRoot);

    cout << "\nHeight of AVL tree: "
         << getHeight(avlRoot);

    if (getHeight(balancedRoot) < getHeight(avlRoot))
        cout << "\nBalanced BST has smaller height.\n";
    else if (getHeight(balancedRoot) > getHeight(avlRoot))
        cout << "\nAVL tree has smaller height.\n";
    else
        cout << "\nBoth trees have equal height.\n";

    return 0;
}
