#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool ifContainKey(char c);
    void put(char c, Node *node);
    Node *get(char c);

private:
    Node *links[26];
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    int insert(string word);

private:
    Node *root;
};

// Node
bool Node::ifContainKey(char c)
{
    return (links[c - 'a'] != NULL);
}

void Node::put(char c, Node *node)
{
    links[c - 'a'] = node;
}

Node *Node ::get(char c)
{
    return links[c - 'a'];
}

// Trie Utility
int Trie::insert(string word)
{
    Node *dummy = root;
    int ans = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        if (!dummy->ifContainKey(word[i]))
        {
            dummy->put(word[i], new Node());
            ++ans;
        }
        dummy = dummy->get(word[i]);
    }

    return ans;
}

int countDistinctSubstrings(string s)
{
    Trie t;
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        ans += t.insert(s.substr(i));
    }

    return ans + 1;
}

int main()
{
    cout << countDistinctSubstrings("aa") << endl;
    cout << countDistinctSubstrings("abab") << endl;
    return 0;
}