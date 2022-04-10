#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    Node *links[2];

public:
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
            if (!dummy->containkeys(bit))
            {
                dummy->put(bit, new Node());
            }
            dummy = dummy->get(bit);
        }
        return;
    }

    int getMax(int num)
    {
        Node *dummy = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (dummy->containkeys(!bit))
            {
                maxNum = maxNum | (1 << i);
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

// Offline Queries
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> contVec;

        int ind = 0;

        // Offline Queries method
        for (int i = 0; i < queries.size(); i++)
        {
            contVec.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(contVec.begin(), contVec.end());
        Trie trie;
        for (int i = 0; i < queries.size(); i++)
        {
            int a1 = contVec[i].first;
            int x1 = contVec[i].second.first;
            int qIndx = contVec[i].second.second;
            while ((nums[ind] <= a1) && (ind < nums.size()))
            {
                trie.insert(nums[ind]);
                ++ind;
            }
            if (ind == 0)
            {
                ans[qIndx] = -1;
            }
            else
            {
                ans[qIndx] = trie.getMax(x1);
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}