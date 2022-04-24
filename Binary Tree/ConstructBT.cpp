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

// Tough Please revise
// Inorder and Postorder
TreeNode *constructTree(vector<int> preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &uMap)
{
    if ((preStart > preEnd) || (inStart > inEnd))
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = uMap[root->val];
    int left = inRoot - inStart;

    root->left = constructTree(preorder, preStart + 1, preStart+left, inorder, inStart, inRoot - 1, uMap);
    root->right = constructTree(preorder, preStart + left + 1, preEnd, inorder, inRoot + 1, inEnd, uMap);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> uMap;
    for (size_t i = 0; i < inorder.size(); i++)
    {
        uMap[inorder[i]] = i;
    }
    return constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size(), uMap);
}

int main()
{
    return 0;
}