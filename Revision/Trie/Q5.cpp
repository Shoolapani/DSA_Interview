#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool ifContainKey(int bit)
    {
        return (links[bit] != nullptr);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node *get(int bit)
    {
        return links[bit];
    }

private:
    Node *links[2];
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *dummy = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!dummy->ifContainKey(bit))
            {
                dummy->put(bit, new Node());
            }
            dummy = dummy->get(bit);
        }
    }

    int maxXOR(int num)
    {
        Node *dummy = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (dummy->ifContainKey(!bit))
            {
                ans = (ans) | (1 << i);
                dummy = dummy->get(!bit);
            }
            else
            {
                dummy = dummy->get(bit);
            }
        }
        return ans;
    }

private:
    Node *root;
};

class Solution
{
public:
    Trie t;
    int findMaximumXOR(vector<int> &nums)
    {
        for (auto &&i : nums)
        {
            t.insert(i);
        }

        int ans = 0;

        for (auto &&i : nums)
        {
            ans = max(ans, t.maxXOR(i));
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {3, 10, 5, 25, 2, 8}, vec1 = {2};

    int maxnum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < 4; j++)
        {
            maxnum = max(maxnum, nums[i] ^ nums[j]);
        }
    }
    cout << maxnum << endl;

    Solution sol;
    cout << sol.findMaximumXOR(nums) << endl;
    return 0;
}