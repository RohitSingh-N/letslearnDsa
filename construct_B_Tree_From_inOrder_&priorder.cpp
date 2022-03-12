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
int findpos(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}
node *solve(node *root, int in[], int pre[], int index, int inorderstart, int inorderend, int n)
{
    if ((index >= n) || (inorderstart > inorderend))
    {
        return NULL;
    }
    int element = pre[index++];
    node *root = new node(element);
    int pos = findpos(in, element, n);

    solve(root->left, in, pre, index, inorderstart, pos - 1, n);
    solve(root->right, in, pre, index, pos + 1, inorderend, n);
    return root;
}
node *buildfrompreorder_inorder(node *root, int in[], int pre[], int n)
{
    int preorderStarting = 0;
    node *ans = solve(root, in, pre, preorderStarting, 0, n - 1, n);
    return ans;
}
void postorder(node *root) // LRN
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    /* 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 8 -1 -1 -1 -1 */
    node *root = NULL;
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    root = buildfrompreorder_inorder(root, in, pre, 6);
    postorder(root);
    return 0;
}
