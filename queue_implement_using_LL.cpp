#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
class queue
{
public:
    node *front;
    node *rear;

    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int x)
    {
        node *newnode = new node(x);
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
            return;
        }

        rear->next = newnode;
        rear = newnode;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "queue is underflow" << endl;
            return;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    // cout << q.peek() << endl;
    // q.pop();
    cout << q.empty();

    return 0;
}
