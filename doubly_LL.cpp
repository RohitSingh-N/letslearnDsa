#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(node *&head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}
void insertattail(node *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *temp = head;
    node *newval = new node(val);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newval;
    newval->prev = temp;
}
void deletehead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletetion(node *&head, int pos)
{
    if (pos == 1)
    {
        deletehead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
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
    display(head);
    deletetion(head, 1);
    display(head);
    cout << endl;
    cout << head->data;

    return 0;
}
