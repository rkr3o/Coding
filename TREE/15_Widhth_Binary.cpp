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

Node *createBinarytree(Node *root)
{
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter left to " << data << endl;
    root->left = createBinarytree(root->left);
    cout << "Enter right to " << data << endl;
    root->right = createBinarytree(root->right);

    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
        int n = q.size();
        res = max(res, n);
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    cout << res;
}
int main()
{
    Node *root = NULL;
    root = createBinarytree(root);
    levelOrder(root);
}