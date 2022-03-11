#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void buildfromlevelorder(node *&root)
{
    cout << "enter data : "
         << " ";
    int data;
    cin >> data;
    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left of : " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter data for right of : " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
void preorder(node *&root, int &count)
{

    if (root == NULL)
    {
        return;
    }
    preorder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    preorder(root->right, count);
}
int main()
{
    /* 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);
    cout << "printing the B Tree: " << endl;
    int count;
    preorder(root, count);
    cout << count << endl;
    return 0;
}
