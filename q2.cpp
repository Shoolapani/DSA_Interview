/*
Find the shortest distance between any 2 nodes in a given binary tree.

 1
/ \
 2     3
/ \ / \
4 5   6 7
/ \ \
8 9 10
/ \
11 12
/
13

return find(path, x) + find(path, y);
            2,4             2,5
            4               7

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node()
        : val{0}, left{NULL}, right{NULL} {}
};

bool isNodePresent(Node *root, Node *node)
{
    if (root == nullptr)
    {
        return NULL;
    }
    if (root == node)
    {
        return true;
    }

    return (isNodePresent(root->left, node) || isNodePresent(root->right, node));
}

Node *findMinPath(Node *root, Node *x, Node *y)
{
    if (root == nullptr)
    {
        return NULL;
    }

    if ((root == x) || (root == y))
    {
        return root;
    }

    Node *left = findMinPath(root->left, x, y);
    Node *right = findMinPath(root->right, x, y);

    if (left && right)
    {
        return root;
    }

    if (left)
    {
        return left;
    }

    if (right)
    {
        return right;
    }
}

int findDistance(Node *root, Node *x, Node *y)
{
    Node *path = nullptr;
    if (isNodePresent(root, x) && (isNodePresent(root, y)))
    {
        // path = findMinPath();
    }
    else
    {
        return - 1;
    }

    // return findLevel(path,x)+findLevel(path,y);
}

int main()
{
    return 0;
}