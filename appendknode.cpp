#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insertattail(node *&head, int val)
{
    node *temp = head;
    node *ptr = new node(val);
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}
void insertathead(node *&head, int val)
{
    node *ptr = new node(val);
    ptr->next = head;
    head = ptr;
}

void insertatmiddle(node *&head, int val, int pos)
{
    node *ptr = new node(val);
    node *temp = head;
    if (pos == head->data)
    {
        insertathead(head, val);
    }
    for (int i = 0; i < pos; i++)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
}
int length(node *&head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node *appendk(node *&head, int k)
{
    node *tail = head;
    node *newtail;
    node *newhead;

    int count = 1;
    int l = length(head);
    k = k % l;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertathead(head, 5);
    insertatmiddle(head, 6, 2);
    display(head);
    cout << head->data << endl;
    node *newhead = appendk(head, 2);
    display(newhead);
    cout << endl;
    cout << newhead->data << endl;
    return 0;
}
