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
void solve(node *root, int &count, vector<int> path, int k)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    solve(root->left, count, path, k);
    solve(root->right, count, path, k);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int maxisum(node *root, int k)
{
    int count = 0;
    vector<int> path;
    solve(root, count, path, k);
    return count;
}
int main()
{
    /* 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 8 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);
    int k = 5;
    int ans;
    ans = maxisum(root, k);

    cout << ans << " ";

    return 0;
}
