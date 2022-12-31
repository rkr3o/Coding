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
int sizeofBinarytree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + sizeofBinarytree(root->left) + sizeofBinarytree(root->right);
}
// check for maximum

int maximumNode(Node *root)
{
       if(root == NULL)return 0 ;

       int left = sizeofBinarytree(root->left);
       int right = sizeofBinarytree(root->right);

       return  max(root->data , max(maximumNode(root->left), maximumNode(root->right)));
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
    cout << sizeofBinarytree(root);
    cout << endl;
    cout << maximumNode(root) << endl;
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