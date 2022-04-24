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

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
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

// Recursive
int maxDepth(TreeNode *root)
{
    if (root = nullptr)
    {
        return 0;
    }

    return (1 + max(maxDepth(root->left), maxDepth(root->right)));
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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodeMap;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    vector<vector<int>> ans;

    // Initial root
    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();

        // x= vertical , y= level
        int x = p.second.first, y = p.second.second;
        nodeMap[x][y].insert(p.first->val);

        if (p.first->left != NULL)
        {
            todo.push({p.first->left, {x - 1, y + 1}});
        }

        if (p.first->right != NULL)
        {
            todo.push({p.first->right, {x + 1, y + 1}});
        }
    }

    // it Becomes Pair
    for (auto &&it : nodeMap)
    {
        vector<int> ds;
        for (auto &&q : it.second)
        {
            ds.insert(ds.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(ds);
    }

    return ans;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, Node *> nodeMap;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        // x= vertical
        int x = temp.second;
        if (temp.first->left != NULL)
        {
            q.push({temp.first->left, x - 1});
        }
        if (temp.first->right != NULL)
        {
            q.push({temp.first->right, x + 1});
        }
        nodeMap[x] = temp.first;
    }

    for (auto &&i : nodeMap)
    {
        ans.push_back(i.second->data);
    }
    return ans;
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    map<int, Node *> nodeMap;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int x = p.second;
        if (p.first->left != NULL)
        {
            q.push({p.first->left, x - 1});
        }
        if (p.first->right != NULL)
        {
            q.push({p.first->right, x + 1});
        }

        if (nodeMap.find(x) == nodeMap.end())
        {
            nodeMap.insert({x, p.first});
        }
    }
    for (auto &&i : nodeMap)
    {
        ans.push_back(i.second->data);
    }

    return ans;
}

bool nodePath(TreeNode *a, int b, vector<int> &ans)
{
    if (a == NULL)
    {
        return false;
    }

    ans.push_back(a->val);
    if (a->val == b)
    {
        return true;
    }

    if ((nodePath(a->left, b, ans)) || (nodePath(a->right, b, ans)))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    if (A == NULL)
    {
        return ans;
    }
    nodePath(A, B, ans);
    return ans;
}

int widthOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<TreeNode *, unsigned int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int leftMost, rightMost;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode *dummy = q.front().first;
            int cur_id = q.front().second - min;
            q.pop();

            if (i == 0)
            {
                leftMost = cur_id;
            }
            if (i == size - 1)
            {
                rightMost = cur_id;
            }
            if (dummy->left != NULL)
            {
                q.push({dummy->left, (unsigned int)2 * cur_id + 1});
            }
            if (dummy->right != NULL)
            {
                q.push({dummy->right, (unsigned int)2 * cur_id + 2});
            }
        }
        ans = max(ans, rightMost - leftMost + 1);
    }

    return ans;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> pre, in, post;
    if (root == NULL)
    {
        return ans;
    }
    stack<pair<BinaryTreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }

        else
        {
            post.push_back(it.first->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

// diameterOfBinaryTree
// O(N^2)
int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

void helper(TreeNode *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    ans = max(ans, lh + rh);
    helper(root->left, ans);
    helper(root->right, ans);
}

int diameterOfBinaryTree2(TreeNode *root)
{
    int ans = 0;
    helper(root, ans);
    return ans;
}

// O(N)
int height(TreeNode *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left, ans);
    int rh = height(root->right, ans);

    ans = max(ans, lh + rh);
    return 1 + (max(lh, rh));
}

int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    height(root, ans);
    return ans;
}

// Recursive Way
TreeNode *invertTree(TreeNode *root)
{
    if (root)
    {
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    return root;
}

// Non-recursive way
TreeNode *invertTree2(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        auto p = st.top();
        st.pop();
        if (p != NULL)
        {
            st.push(p->left);
            st.push(p->right);
            swap(p->left, p->right);
        }
    }
    return root;
}

// O(N^2) approach
bool isBalanced2(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    if (abs(lh - rh) > 1)
    {
        return false;
    }

    if ((isBalanced2(root->left) == false) || (isBalanced2(root->right) == false))
    {
        return false;
    }
    return true;
}

// O(N)
int DFSHeight(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = DFSHeight(root->left);
    int rh = DFSHeight(root->right);

    if ((lh == -1) || (rh == -1))
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root)
{
    return (DFSHeight(root) != -1);
}

// My approach
bool isSameTree2(TreeNode *p, TreeNode *q)
{
    if ((p == NULL) && (q == NULL))
    {
        return true;
    }
    if ((p != nullptr) && (q != nullptr))
    {
        if (p->val != q->val)
        {
            return false;
        }
    }
    if ((p == NULL) && (q != nullptr))
    {
        return false;
    }
    if ((q == NULL) && (p != nullptr))
    {
        return false;
    }
    if ((isSameTree2(p->left, q->left) == false) || (isSameTree2(p->right, q->right) == false))
    {
        return false;
    }
    return true;
}

// Striver Approach
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if ((p == NULL) || (q == NULL))
    {
        return (p == q);
    }

    return (p->val == q->val) && ((isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right)));
}

bool ifSymmetric(TreeNode *left, TreeNode *right)
{
    if ((left == NULL) || (right == NULL))
    {
        return (left == right);
    }

    if (left->val != right->val)
    {
        return false;
    }

    return (ifSymmetric(left->left, right->right) && ifSymmetric(left->right, right->left));
}

bool isSymmetric(TreeNode *root)
{
    return (root == NULL) || (ifSymmetric(root->left, root->right));
}

// Recursive
// Reverse Preorder Right left Root
// O(N) O(N)
TreeNode *prevNode = NULL;
void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->right = prevNode;
    root->left = NULL;
    prevNode = root;
    return;
}

// Iterative
// Preorder
// O(N) O(N)
void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *subroot = st.top();
        st.pop();

        if (subroot->right)
        {
            st.push(subroot->right);
        }

        if (subroot->left)
        {
            st.push(subroot->left);
        }

        if (!st.empty())
        {
            subroot->right = st.top();
        }
        subroot->left = NULL;
    }
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

    map<int, map<int, int>> m;
    m[0][1] = 1;

    return 0;
}