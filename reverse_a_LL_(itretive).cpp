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
node *reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *nextptr;
    while (curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}
int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    display(head);
    node *newhead = reverse(head);
    display(newhead);

    cout << endl;
    cout << newhead->data << endl;
    return 0;
}
