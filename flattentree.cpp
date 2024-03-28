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
void flatten(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }

    flatten(root->right);
}
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
    root->right->left = new node(6);
    root->right->right = new node(7);
    flatten(root);
    preorderprint(root);
    return 0;
}
// result is :1 2 4 5 3 6 7