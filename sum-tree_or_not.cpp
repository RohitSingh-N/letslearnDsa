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
pair<bool, int> issumtreefast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = issumtreefast(root->left);
    pair<bool, int> right = issumtreefast(root->right);
    bool op1 = left.first;
    bool op2 = right.first;
    bool cond = root->data == left.second + right.second;

    pair<bool, int> ans;
    if (op1 && op2 && cond)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool issumtree(node *root)
{
    return issumtreefast(root).first;
}

int main()
{
    /* 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);

    bool sum = issumtree(root);
    if (sum)
    {
        cout << "Tree is Sum Tree" << endl;
    }
    else
    {
        cout << "Tree is not a Sum Tree" << endl;
    }
    return 0;
}
