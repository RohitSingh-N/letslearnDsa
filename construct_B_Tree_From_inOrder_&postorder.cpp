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
void create_mapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}
node *solve(int in[], int postorder[], int &index, int inorderstart, int inorderend, int n, map<int, int> nodeToIndex)
{
    if ((index < 0) || (inorderstart > inorderend))
    {
        return NULL;
    }
    int element = postorder[index--];
    node *root = new node(element);
    int pos = nodeToIndex[element];
    root->right = solve(in, postorder, index, pos + 1, inorderend, n, nodeToIndex);
    root->left = solve(in, postorder, index, inorderstart, pos - 1, n, nodeToIndex);

    return root;
}
node *buildfrompostorder_inorder(int in[], int postorder[], int n)
{
    map<int, int> nodeToindex;
    create_mapping(in, nodeToindex, n);
    int postorderStarting = n - 1;
    node *ans = solve(in, postorder, postorderStarting, 0, n - 1, n, nodeToindex);
    return ans;
}
void preorder(node *root) // LRN
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    /* 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 8 -1 -1 -1 -1 */
    node *root = NULL;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postorder[] = {8, 4, 5, 2, 6, 7, 3, 1};
    root = buildfrompostorder_inorder(in, postorder, 8);
    preorder(root);
    return 0;
}
