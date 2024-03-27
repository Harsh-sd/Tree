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
void sumReplacement(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
};
void preorderprint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    sumReplacement(root);
    preorderprint(root);
    return 0;
}
// result is :15 11 4 5 3