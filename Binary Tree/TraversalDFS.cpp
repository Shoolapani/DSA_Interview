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

class Solution
{
public:
    void preorderTraverse(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val << " ";
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preOrder;
        if (root == NULL)
        {
            return preOrder;
        }

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *tempNode = st.top();
            st.pop();
            if (tempNode->right != NULL)
            {
                st.push(tempNode->right);
            }
            if (tempNode->left != NULL)
            {
                st.push(tempNode->left);
            }
            preOrder.push_back(tempNode->val);
        }
        return preOrder;
    }

    void inorderTraverse(TreeNode *root)
    {
        if (root != NULL)
        {
            return;
        }
        inorderTraverse(root->left);
        cout << root->val << " ";
        inorderTraverse(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inOrder;
        stack<TreeNode *> st;
        while (true)
        {
            if (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                root = st.top();
                inOrder.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        return inOrder;
    }

    void postorderTraverse(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }

    // Using 2 Stacks
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *tempNode = s1.top();
            s2.push(s1.top());
            s1.pop();
            if (tempNode->left != NULL)
            {
                s1.push(tempNode->left);
            }
            if (tempNode->right != NULL)
            {
                s1.push(tempNode->right);
            }
        }

        while (!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }

    // Using 1 Stacks
    vector<int> postorderTraversal2(TreeNode *cur)
    {
        vector<int> postOrder;
        if (cur == NULL)
            return postOrder;

        stack<TreeNode *> st;
        while (cur != NULL || !st.empty())
        {

            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else
                    cur = temp;
            }
        }
        return postOrder;
    }
};

int main()
{
    return 0;
}