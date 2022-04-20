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

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x = 0)
    {
        data = x;
        left = right = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);
    return temp;
}

void viewLeft(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    viewLeft(root->left, level + 1, ans);
    viewLeft(root->right, level + 1, ans);
    return;
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    viewLeft(root, 0, ans);
    return ans;
}

void viewRight(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    viewRight(root->right, level + 1, ans);
    viewRight(root->left, level + 1, ans);

    return;
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    viewRight(root, 0, ans);
    return ans;
}

TreeNode *invertTree(TreeNode *root)
{
    if (root != nullptr)
    {
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    return root;
}

int maxDepth(TreeNode *root)
{
    if (root = nullptr)
    {
        return 0;
    }

    return (1 + max(maxDepth(root->left), maxDepth(root->right)));
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ds;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode *dummy = q.front();
            q.pop();
            if (dummy->left != nullptr)
            {
                q.push(dummy->left);
            }
            if (dummy->right != NULL)
            {
                q.push(dummy->right);
            }
            ds.push_back(dummy->val);
        }
        ans.push_back(ds);
    }
    return ans;
}

// BFS
int maxDepth2(TreeNode *root)
{
    int ans = 1;
    if (root == nullptr)
    {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ds;
        ++ans;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode *dummy = q.front();
            q.pop();
            if (dummy->left != nullptr)
            {
                q.push(dummy->left);
            }
            if (dummy->right != NULL)
            {
                q.push(dummy->right);
            }
            ds.push_back(dummy->val);
        }
    }
    return ans;
}

// Om Namah sivay
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        vector<int> ds;
        int size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode *dummy = q.front();
            q.pop();
            if (dummy->left != NULL)
            {
                q.push(dummy->left);
            }
            if (dummy->right != NULL)
            {
                q.push(dummy->right);
            }
            ds.push_back(dummy->val);
        }
        if (flag == false)
        {
            reverse(ds.begin(), ds.end());
        }
        flag = !flag;
        ans.push_back(ds);
    }
    return ans;
}

vector<int> bottomView(Node *root)
{
    
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    for (auto &&i : leftView(root))
    {
        cout << i << " ";
    }

    return 0;
}