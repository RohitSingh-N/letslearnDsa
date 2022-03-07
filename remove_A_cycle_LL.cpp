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
void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *cyclenode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cyclenode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cyclenode;
}
bool detectcycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
void removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    insertattail(head, 6);
    makecycle(head, 3);
    cout << detectcycle(head);
    removecycle(head);
    cout << endl;
    cout << detectcycle(head);

    return 0;
}
