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
void traverse_left(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverse_left(root->left, ans);
    }
    else
    {
        traverse_left(root->right, ans);
    }
}
void traverse_leaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverse_leaf(root->left, ans);
    traverse_leaf(root->right, ans);
}
void traverse_right(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverse_right(root->right, ans);
    }
    else
    {
        traverse_right(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary_traversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);

    traverse_left(root->left, ans);
    traverse_leaf(root->left, ans);
    traverse_leaf(root->right, ans);
    traverse_right(root->right, ans);

    return ans;
}
int main()
{
    /* 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 8 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);
    vector<int> ans;
    ans = boundary_traversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
