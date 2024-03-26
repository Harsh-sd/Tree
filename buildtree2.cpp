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

int search(int inorder[], int curr, int start, int end)
{
    for (int i = start; i <= end; i++) // Adjusted the loop condition to include 'end'
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *buildtree(int postorder[], int inorder[], int start, int end)
{
    static int idx = end;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    node *n = new node(curr);
    idx--; // Decrement idx before recursive call
    if (start == end)
    {
        return n;
    }
    int pos = search(inorder, curr, start, end);
    if (pos == -1)
    {
        // Element not found, should not happen in a valid traversal
        // This could be due to an incorrect traversal sequence
        return NULL;
    }
    n->right = buildtree(postorder, inorder, pos + 1, end);
    n->left = buildtree(postorder, inorder, start, pos - 1);
    return n;
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
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = buildtree(postorder, inorder, 0, 4);
    preorderprint(root);
    return 0;
}
// result is: 1 2 4 3 5