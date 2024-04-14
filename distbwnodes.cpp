#include <iostream>
using namespace std;
// provided structure for the tree
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    };
};
node *lca(node *root, int n1, int n2)
{
    // base condition to check whether the tree is present or not
    if (root == NULL)
    {
        return 0;
    }
    // if rrot equal to which we are checking the lca then return root
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left != NULL)
    {
        return left;
    }

    return right;
};
int findDist(node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }
    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    int right = findDist(root->right, k, dist + 1);
    return (right != -1) ? right : -1;
}
int distbwnodes(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return 0;
    }
    // first we have to find the lca
    node *LCA = lca(root, n1, n2);
    // then we have to find dist from lca to node
    int d1 = findDist(LCA, n1, 0);
    int d2 = findDist(LCA, n2, 0);
    return d1 + d2;
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
    node *ancestor = lca(root, 7, 6);
    if (ancestor != NULL)
    {
        cout << "Lowest Common Ancestor: " << ancestor->data;
    }
    else
    {
        cout << "One or both nodes not found in the tree.";
    }
    cout << endl;
    cout << distbwnodes(root, 7, 6);
}