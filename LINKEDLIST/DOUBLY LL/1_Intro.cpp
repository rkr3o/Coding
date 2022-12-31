#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int n)
    {
        data = n;
        next = NULL;
        prev = NULL;
    }
};
void getDetails(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertHead(Node *&head, int val)
{
    Node *temp = head;
    Node *n = new Node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertTail(Node *&head, int val)
{
    Node *temp = head;
    Node *n = new Node(val);

    if (head == NULL)
    {
        insertHead(head, val);
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void insertMid(Node *&head, int val, int pos)
{
    Node *temp = head;

    Node *n = new Node(val);
    int counter = 1;
    if (pos == 1)
    {
        insertHead(head , val );
        return;
    }
    while (counter != pos - 1)
    {
        temp = temp->next;
        counter++;
    }

    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

int main()
{
    Node *head = new Node(0);
    Node *head1 = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        head->next = new Node(x);
        head = head->next;
    }

    getDetails(head1);
    cout << endl;
    insertTail(head1, 10);
    insertTail(head1, 20);
    insertTail(head1, 30);
    insertTail(head1, 40);
    getDetails(head1);
    cout << endl;
    insertHead(head1, 40);
    insertHead(head1, 40);
    insertHead(head1, 40);
    insertHead(head1, 40);
    getDetails(head1);
    insertMid(head1, 1010, 3);
    cout << endl;
    getDetails(head1);
    cout << endl;
    insertMid(head1, 10110, 1);
    cout << endl;
}