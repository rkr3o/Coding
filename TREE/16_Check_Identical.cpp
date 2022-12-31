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

bool checkIdentical(Node *root, Node *root2)
{
    if (root == NULL and root2 == NULL)
    {
        return true;
    }
    if (root == NULL and root2 != NULL)
    {
        return false;
    }
    if (root != NULL and root2 == NULL)
    {
        return false;
    }

    return (root->data == root2->data and checkIdentical(root->left, root2->left) and checkIdentical(root->right, root2->right));
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

    Node *root2 = new Node(4);
    root2->left = new Node(6);
    root2->right = new Node(7);
    root2->left->left = new Node(9);
    root2->left->left->left = new Node(99);
    root2->left->right = new Node(10);
    root2->right->left = new Node(11);
    root2->right->right = new Node(12);

    cout << checkIdentical(root, root2);
    cout << endl;
    if (checkIdentical(root, root2) == true)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

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