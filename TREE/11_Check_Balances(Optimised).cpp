#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int n)
    {
        data = n;
        left = right = NULL;
    }
};
int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);

    return 1 + max(leftH, rightH);
}
bool checkBalanced(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);

    if (leftH == -1 or rightH == -1)
    {
        return -1;
    }
    if (abs(leftH - rightH) > 1)
    {
        return -1;
    }
    return 1 + max(rightH, leftH);
}
int main()
{

    Node *root = new Node(4);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(9);
    root->left->left->left = new Node(99);
    root->left->right = new Node(10);
    root->right->left = new Node(11);
    root->right->right = new Node(12);
    cout << checkBalanced(root);
    return 0;
}
/*
            (4)
          /    \
         /      \
      (6)        (7)
      / \       /   \
    (9) (10) (11)   (12)
    /
  (99)

*/