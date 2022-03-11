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
pair<int, int> diameterfast(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(node *root)
{
    return diameterfast(root).first;
}

int main()
{
    /* 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 */
    node *root = NULL;
    buildfromlevelorder(root);

    int diameters = diameter(root);
    cout << "diameter of b-tree is : " << diameters << endl;
    return 0;
}
