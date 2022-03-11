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

vector<int> bottom_view(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> nodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second;

        nodes[hd] = frontnode->data;

        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, hd - 1));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }

    return ans;
}
int main()
{
    /* 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 8 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);
    vector<int> ans;
    ans = bottom_view(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
