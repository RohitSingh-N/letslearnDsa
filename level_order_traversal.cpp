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
node *build_tree(node *root)
{
    cout << "enter the data : " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter data for inserting in left of binary tree : " << data << endl;
    root->left = build_tree(root->left);
    cout << "enter data for inserting in right of binary tree: " << data << endl;
    root->right = build_tree(root->right);
    return root;
}
void level_order_trav(node *root)
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
int main()
{
    /*1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 */
    node *root = NULL;
    root = build_tree(root);
    level_order_trav(root);
    return 0;
}
