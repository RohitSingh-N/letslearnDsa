#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                parent = index;
            }
            else
            {
                return;
            }
        }
    }
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int parent = i / 2;
            int rightchild = i * 2 + 1;
            int leftchild = i * 2;

            if (leftchild < size && arr[i] < arr[leftchild])
            {
                swap(arr[i], arr[leftchild]);
                i = leftchild;
            }
            else if (rightchild < size && arr[i] < arr[rightchild])
            {
                swap(arr[i], arr[rightchild]);
                i = rightchild;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap hp;
    hp.insert(55);
    hp.insert(44);
    hp.insert(60);
    hp.insert(59);
    hp.print();
    cout << endl;
    hp.deletefromheap();
    hp.print();
    return 0;
}
