#include <bits/stdc++.h>
using namespace std;

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
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
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