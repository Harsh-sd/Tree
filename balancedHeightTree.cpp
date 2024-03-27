#include <iostream>
#include <cmath>
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
// height we are calculating to check that it is balaned or not
int calcHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);
    // returning maximum from left and right height and adding the root node
    return max(lh, rh) + 1;
}
bool checkBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    // if at any position in the left subtree
    if (checkBalanced(root->left) == false)
    {
        return false;
    }
    // if at any position in the right subtree
    if (checkBalanced(root->right) == false)
    {
        return false;
    }
    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);
    // for the absolute checking of the subtree
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->right = new node(5);
    if (checkBalanced(root))
    {
        cout << "tree is balanced";
    }
    else
    {
        cout << "tree is not balanced";
    }
    cout<<endl;
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root->left->left = new node(4);
    if (checkBalanced(root1))
    {
        cout << "tree is balanced";
    }
    else
    {
        cout << "tree is not balanced";
    }
    return 0;
}
// result is :tree is not balanced
// result is :tree is  balanced