#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = NULL;
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
int main()
{

    // we can do this also but this is not a recommended practise
    /*
       Node *head = NULL;
       Node *second = NULL;
       Node *third = NULL;

       head = new Node();
       second = new Node();
       third = new Node();

       head->data = 40;
       head->next = second;
       second->data = 50;
       second->next = third;
       third->data = 60;
       third->next = NULL;
   */

    Node *head = new Node(0);
    Node* head1 = head;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        head->next = new Node(x);
        head = head->next;
    }

    getDetails(head);
}