#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[2];
    bool containkeys(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};

// Trie Contain every Element of an array
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
            // Check if bit is set or not
            int bit = (num >> i) & 1;
            if (!dummy->containkeys(bit))
            {
                dummy->put(bit, new Node());
            }
            dummy = dummy->get(bit);
        }
        return;
    }

    // Find the max
    int findMax(int num)
    {
        int maxNum = 0;
        Node *dummy = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (dummy->containkeys(!bit))
            {
                maxNum = maxNum | (1 << i);
                // Please see this as I forgot this  !bit as we are opposite bit;
                dummy = dummy->get(!bit);
            }
            else
            {
                dummy = dummy->get(bit);
            }
        }

        return maxNum;
    }

private:
    Node *root;
};

class Solution
{
public:
    Trie trie;
    int findMaximumXOR(vector<int> &nums)
    {
        int maxNum = 0;
        for (auto &&it : nums)
        {
            trie.insert(it);
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            maxNum = max(maxNum, trie.findMax(nums[i]));
        }
        return maxNum;
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