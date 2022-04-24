#include <bits/stdc++.h>
using namespace std;

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

// O(N) O(N)
void changeTree(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    int sum = 0;
    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }

    if (root->data >= sum)
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }
    else
    {
        root->data = sum;
    }

    changeTree(root->left);
    changeTree(root->right);
    sum = 0;
    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }

    if (root->data <= sum)
    {
        root->data = sum;
    }
}

BinaryTreeNode *newNode(int data)
{
    BinaryTreeNode *temp = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    BinaryTreeNode *root = newNode(40);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(1);
    root->right = newNode(30);
    root->right->left = newNode(70);
    root->right->right = newNode(20);

    changeTree(root);
    int x = 2;
    return 0;
}