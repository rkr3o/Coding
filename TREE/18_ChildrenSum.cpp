
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int n)
    {
        data = n;
        left = right = NULL;
    }
};
int getans(TreeNode *root)
{
    int a = 0, b = 0;
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    if (root->left)
    {
        a = getans(root->left);
    }
    if (root->right)
    {
        b = getans(root->right);
    }
    if ((a + b) == root->data)
    {
        return root->data + a + b;
    }
    return 0;
}
bool isSumTree(TreeNode *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 1;
    }
    int ans = getans(root);
    if (ans / 2 == root->data)
    {
        return 1;
    }
    return 0;
}

int main()
{

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(6);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(9);
    root->left->left->left = new TreeNode(99);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(12);
    cout << getans(root);
}