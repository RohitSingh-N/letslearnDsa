#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int da)
    {
        this->data = da;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insertinbst(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertinbst(root->right, d);
    }
    else
    {
        root->left = insertinbst(root->left, d);
    }
    return root;
}
void level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void binarysearch_tree(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertinbst(root, data);
        cin >> data;
    }
}
int main()
{
    node *root = NULL;
    cout << "enter data to insert in bst: " << endl;
    binarysearch_tree(root);
    cout << "printing the bST: " << endl;
    level_order_traversal(root);

    return 0;
}
