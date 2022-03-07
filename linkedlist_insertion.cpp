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
bool search(node *&head, int k)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void insertatmiddle(node *&head, int val, int pos)
{
    node *ptr = new node(val);
    node *temp = head;
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
    cout << search(head, 3);
    cout << endl;
    cout << head->data << endl;
    return 0;
}
