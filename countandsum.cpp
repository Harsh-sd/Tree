// counting and summing im the binary tree
#include <iostream>
using namespace std;
// provided structure for the tree
struct node
{
    int data;
    node *left;
    node *right;

public:
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    };
};
int countnodes(node *root)
{
    if (root == NULL)
    {
        return 0; // Return 0 for an empty subtree
    }
    return countnodes(root->left) + countnodes(root->right) + 1;
}
int sumofBinaryTree(node *root)
{
    if (root == NULL)
    {
        return 0; // Return 0 for an empty subtree
    }
    return sumofBinaryTree(root->left) + sumofBinaryTree(root->right) + root->data;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << countnodes(root);
    cout << endl;
    cout << sumofBinaryTree(root);
}

// Result are: 7 , 28