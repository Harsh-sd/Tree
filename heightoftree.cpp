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
// calculating the height of the tree:>Height is defined as the deepest node in the tree from the root node
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
// calculating the diameter of tree:>Diameter is defined as the maximim number odf modes between the two adjecent nodes
int calcDiameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = calcHeight(root->left);  // Height of left subtree
    int rh = calcHeight(root->right); // Height of right subtree

    // Diameter passing through the current node
    int currentDiameter = lh + rh + 1;

    // Recursively calculate diameters of left and right subtrees
    int ld = calcDiameter(root->left);
    int rd = calcDiameter(root->right);

    // Return the maximum of the three diameters
    return max(currentDiameter, max(ld, rd));
}
// time complexity is O(n)
int calcDiameters(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = calcDiameters(root->left, &lh);
    int rd = calcDiameters(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(ld, rd));
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->right = new node(3);
    root->left->right->right = new node(4);
    root->left->left = new node(5);
    root->left->left->right = new node(6);
    root->left->left->left = new node(7);
    root->left->left->left->left = new node(8);
    cout << calcHeight(root);
    cout << endl;
    cout << calcDiameter(root);
    cout << endl;
    int height = 0;
    cout << calcDiameters(root, &height);
};
// Result:height is 5
// Diameter is 6
// Here the time complexity is O(n^2)because in the diamter we are using height function externally
// to reduce the time complexity we ahve to use height in the diameter function inside
