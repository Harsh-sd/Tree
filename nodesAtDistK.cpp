#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printSubtreenodes(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    printSubtreenodes(root->left, k - 1);
    printSubtreenodes(root->right, k - 1);
}

int printnodesatk(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubtreenodes(root, k);
        return 0;
    }

    int dl = printnodesatk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreenodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printnodesatk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreenodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
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

    cout << "Nodes at distance 1 from node 2: ";
    printnodesatk(root, root->left, 1);
    cout << endl;

    return 0;
}
// return 4 5 1
