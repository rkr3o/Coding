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
void reverse(Node* &head )
{
      Node* first = NULL;
      Node* second = head;
      while(second!=NULL)
      {
          first = second->prev;
          second->prev = second->next;
          second->next = first ;
          second = second->prev;
      }

      if(first != NULL)
      {
        head = first->prev;
      }
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
    insertHead(head1, 50);
    
    getDetails(head1);
    cout<<endl;
    reverse(head);
    getDetails(head);
}