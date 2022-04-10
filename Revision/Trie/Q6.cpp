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
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int ind = 0;
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> offlineQueries;
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < queries.size(); i++)
        {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        for (size_t i = 0; i < queries.size(); i++)
        {
            int a1 = offlineQueries[i].first;
            int x1 = offlineQueries[i].second.first;
            int qIndx = offlineQueries[i].second.second;
            while ((ind < nums.size()) && (nums[ind] <= a1))
            {
                t.insert(nums[ind]);
                ++ind;
            }
            if (ind == 0)
            {
                ans[qIndx] = -1;
            }
            else
            {
                ans[qIndx] = t.maxXOR(a1);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}