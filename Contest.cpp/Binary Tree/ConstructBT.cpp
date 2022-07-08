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

    root->left = constructTree(preorder, preStart + 1, preStart + left, inorder, inStart, inRoot - 1, uMap);
    root->right = constructTree(preorder, preStart + left + 1, preEnd, inorder, inRoot + 1, inEnd, uMap);
    return root;
}

TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> uMap;
    for (size_t i = 0; i < inorder.size(); i++)
    {
        uMap[inorder[i]] = i;
    }
    return constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size(), uMap);
}

// Construct Binary Tree from Inorder and Postorder Traversal
TreeNode *construct(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> uMap)
{
    if ((inStart > inEnd) || (postStart < postEnd))
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postStart]);

    int inRoot = uMap[root->val];
    int leftRem = inRoot - inStart;

    root->left = construct(inorder, inStart, inRoot - 1, postorder, inRoot + 1, inRoot + leftRem, uMap);
    root->right = construct(inorder, inStart + 1, inEnd, postorder, inRoot + leftRem + 1, postEnd, uMap);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> uMap;
    for (size_t i = 0; i < inorder.size(); i++)
    {
        uMap[inorder[i]] = i;
    }

    return construct(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1, 0, uMap);
}

int main()
{
    return 0;
}