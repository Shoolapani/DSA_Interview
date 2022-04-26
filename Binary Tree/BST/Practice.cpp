#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

Node *connect(Node *root)
{
    if (root == NULL)
    {
        return root;
    }

    vector<vector<Node *>> level;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<Node *> ds;
        for (size_t i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            ds.push_back(temp);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        level.push_back(ds);
    }

    for (size_t i = 1; i < level.size(); i++)
    {
        Node *first = level[i][0];
        for (size_t j = 1; j < level[i].size(); j++)
        {
            Node *temp = level[i][j];
            // if (j == level[i].size() - 1)
            // {
            //     temp->next = NULL;
            //     continue;
            // }
            first->next = temp;
            first = temp;
        }
    }
    return root;
}

TreeNode *searchBST(TreeNode *root, int val)
{
    // if we found the val or root is NULL then return root
    // as told in question
    if ((root == nullptr) || (root->val == val))
    {
        return root;
    }

    if (val < root->val)
    {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

// Iterative
TreeNode *searchBST(TreeNode *root, int val)
{
    while ((root != NULL) && (root->val != val))
    {
        if (val < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

bool validBST(TreeNode *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if ((root->val >= max) && (root->val <= min))
    {
        return false;
    }
    return (validBST(root->left, min, root->val) && (validBST(root->right, root->val, max)));
}

bool isValidBST(TreeNode *root)
{
    return validBST(root, INT_MIN, INT_MAX);
}

// Iterative O(H)
TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while ((root != NULL))
    {
        if (((p->val < root->val) && (q->val > root->val)) || ((p->val > root->val) && (q->val < root->val)))
        {
            return root;
        }

        if ((root->val == p->val) || (root->val == q->val))
        {
            return root;
        }

        if ((p->val < root->val) && (q->val < root->val))
        {
            root = root->left;
        }

        if ((p->val > root->val) && (q->val > root->val))
        {
            root = root->right;
        }
    }
    return root;
}

// Recursive
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }

    int curr = root->val;

    if ((p->val < curr) && (q->val < curr))
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    if ((p->val > curr) && (q->val > curr))
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

int main()
{
    return 0;
}