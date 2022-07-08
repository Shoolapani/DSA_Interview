#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    int ans = 0;
    while (root)
    {
        if (root->val == X)
        {
            ans = max(ans, root->val);
            break;
        }

        if (X < root->val)
        {
            root = root->left;
        }

        else if (X >= root->val)
        {
            ans = max(ans, root->val);
            root = root->right;
        }
    }
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans = INT_MAX;
    while (node)
    {
        if (node->data == x)
        {
            ans = node->data;
            return ans;
        }

        if (x < node->data)
        {
            ans = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return ans;
}

int main()
{
    return 0;
}