// we have to print all the nodes at distance k from the target node#include <iostream>
#include <iostream>

using namespace std;

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
    }
};
// case :1 , when we are finding the nodes in a subtree
void printSubtree(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    };
    printSubtree(root->left, k - 1);
    printSubtree(root->right, k - 1);
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
    printSubtree(root, 2);
    return 0;
}