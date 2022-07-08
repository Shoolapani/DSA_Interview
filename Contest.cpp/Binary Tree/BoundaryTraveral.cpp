#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *root)
{
    return ((root->left == NULL) && (root->right == NULL));
}

void addLeft(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
        {
            ans.push_back(cur->data);
        }

        if (cur->left != NULL)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
}

void addLeaf(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    addLeaf(root->left, ans);
    addLeaf(root->right, ans);
}

void addRight(TreeNode<int> *root, vector<int> &ans)
{
    vector<int> temp;
    TreeNode<int> *cur = root->right;
    while (cur)
    {
        if (!isLeaf(cur))
        {
            temp.push_back(cur->data);
        }
        if (cur->right != NULL)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);
    return ans;
}

int main()
{
    return 0;
}