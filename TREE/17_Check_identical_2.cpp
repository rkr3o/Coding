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

TreeNode *createBinarytree(TreeNode *root)
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new TreeNode(data);
    cout << "Enter to the left of : " << data << endl;
    root->left = createBinarytree(root->left);
    cout << "Enter to the right of : " << data << endl;
    root->right = createBinarytree(root->right);

    return root;
}

vector<int> getPreorder(TreeNode *root)
{
    vector<int> v;

    if (root == NULL)
    {
        return v;
    }

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();

        v.push_back(temp->data);

        if (temp->right)
        {
            s.push(temp->right);
        }

        if (temp->left)
        {
            s.push(temp->left);
        }
    }
    return v;
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

    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(9);
    root2->left->left->left = new TreeNode(99);
    root2->left->right = new TreeNode(10);
    root2->right->left = new TreeNode(11);
    root2->right->right = new TreeNode(12);

    vector<int> Preorder;
    vector<int> Preorder2;
    Preorder = getPreorder(root);
    Preorder2 = getPreorder(root2);

    cout << "preorder of 1 : " << endl;
    for (int i = 0; i < Preorder.size(); i++)
    {
        cout << Preorder[i] << " ";
    }
    cout << endl;
    cout << "Preorder of 2nd : " << endl;
    for (int i = 0; i < Preorder.size(); i++)
    {
        cout << Preorder2[i] << " ";
    }
    cout << endl;

    if (Preorder == Preorder2)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}