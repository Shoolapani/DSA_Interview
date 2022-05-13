#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node *newNode(int data)
{
    Node *node = new Node(data);
    return node;
}

bool isLeaf(Node *node)
{
    return ((node->left == NULL) && (node->right == NULL));
}

bool isSum(Node *root, int s, int currSum)
{
    if (root == NULL)
    {
        return false;
    }

    if ((s == currSum) && (isLeaf(root)))
    {
        return true;
    }

    bool lef = false, rig = false;

    if (root->left)
    {
        lef = isSum(root->left, s, currSum + root->left->data);
    }

    if (root->right)
    {
        rig = isSum(root->right, s, currSum + root->right->data);
    }

    if (lef || rig)
    {
        return true;
    }
    return false;
}

bool hasPathSum(Node *root, int S)
{
    return isSum(root, S, 0 + root->data);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    cout << hasPathSum(root, 4) << endl;
    return 0;
}