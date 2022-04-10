#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    // will tell if specific key is present in specific links
    bool isContainKey(char c)
    {
        return (links[c - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // getting desired location address;
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    int insert(string word)
    {
        Node *dummy = root;
        int ans = 0;

        for (size_t i = 0; i < word.length(); i++)
        {
            if (!dummy->isContainKey(word[i]))
            {
                dummy->put(word[i], new Node());
                ++ans;
            }
            dummy = dummy->get(word[i]);
        }
        return ans;
    }

private:
    Node *root;
};

int countDistinctSubstrings(string &s)
{
    Trie t;
    int ans = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        ans += t.insert(s.substr(i));
    }
    return ans + 1;
}

int main()
{

    return 0;
}