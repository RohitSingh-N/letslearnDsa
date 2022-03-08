#include <iostream>
using namespace std;
#define n 20
class queue
{

    int *arr;
    int front;
    int rear;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    void push(int k)
    {
        if (rear == n - 1)
        {
            cout << "Queue is Full " << endl;
            return;
        }

        rear++;
        arr[rear] = k;

        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty";
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > rear)
        {
            return -1;
        }

        return arr[front];
    }
    bool isemptey()
    {
        if (front == -1 || front > rear)
        {
            return 1;
        }

        return -1;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();
    cout << q.isemptey() << endl;

    return 0;
}
