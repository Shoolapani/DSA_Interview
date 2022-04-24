#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative way, Recursive is better
// O(N) O(N)
// O(N) for both side left and right vector
bool nodePath(TreeNode *root, int p, vector<TreeNode *> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root);
    if (root->val == p)
    {
        return true;
    }
    if ((nodePath(root->left, p, ans)) || (nodePath(root->right, p, ans)))
    {
        return true;
    }
    ans.pop_back();
    return false;
}

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> first, second;
    nodePath(root, p->val, first);
    nodePath(root, q->val, second);

    int i = 0, j = 0;
    while ((i < first.size()) && (j < second.size()))
    {
        if (first[i]->val == second[j]->val)
        {
            ++i, ++j;
        }
        else
        {
            break;
        }
    }

    return first[i - 1];
}

// Recursive
// O(N)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if ((root == NULL) || (root == p) || (root == q))
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
    {
        return right;                                                                     
    }
    if (right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}

int main()
{
    return 0;
}