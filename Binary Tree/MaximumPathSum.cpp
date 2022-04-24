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

int height(TreeNode *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = max(0, height(root->left, ans));
    int rh = max(0, height(root->right, ans));
    ans = max(ans, lh + rh + root->val);
    return ((root->val) + max(lh, rh));
}

int maxPathSum(TreeNode *root)
{
    int ans = -1001;
    height(root, ans);
    return ans;
}

int main()
{
    return 0;
}