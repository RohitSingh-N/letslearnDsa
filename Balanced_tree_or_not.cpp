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
pair<bool, int> isbalancedfast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<int, int> left = isbalancedfast(root->left);
    pair<int, int> right = isbalancedfast(root->right);
    bool op1 = left.first;
    bool op2 = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = left.second + right.second + 1;
    if (op1 && op2 && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isbalanced(node *root)
{
    return isbalancedfast(root).first;
}

int main()
{
    /* 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);

    bool balance = isbalanced(root);
    if (balance)
    {
        cout << "Tree is balaced" << endl;
    }
    else
    {
        cout << "Tree is not balanced" << endl;
    }
    return 0;
}
