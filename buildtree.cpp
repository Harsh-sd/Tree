// Building tree from preorder and inorder

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

// serching the first element from preorder in inorder
int search(int inorder[], int curr, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
node *buildtree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    // to traverse in the preorder
    idx++;
    // making the new tree
    node *n = new node(curr);
    // condition at last point of the tree
    if (start == end)
    {
        return n;
    }
    // serching every element in the inorder
    int pos = search(inorder, curr, start, end);
    if (pos == -1)
    {
        // Element not found, should not happen in a valid traversal
        // This could be due to an incorrect traversal sequence
        return NULL;
    }
    // based on its pos in inorder keepinh in the tree
    n->left = buildtree(preorder, inorder, start, pos - 1);
    n->right = buildtree(preorder, inorder, pos + 1, end);
    return n;
}
// printing in the preorder format
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
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = buildtree(preorder, inorder, 0, 4);
    preorderprint(root);
    return 0;
}

// result is: 1 2 4 3 5