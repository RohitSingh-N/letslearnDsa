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
void solve(node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}
vector<int> left_view(node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
int main()
{
    /* 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 8 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);
    vector<int> ans;
    ans = left_view(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
