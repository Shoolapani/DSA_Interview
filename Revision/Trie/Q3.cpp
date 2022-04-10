#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool containKeys(char c)
    {
        return (links[c - 'a'] != NULL);
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    Node *get(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        this->flag = true;
    }

    bool getEnd()
    {
        return this->flag;
    }

private:
    Node *links[26];
    bool flag = false;
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *dummy = root;

        for (size_t i = 0; i < word.size(); i++)
        {
            if (!dummy->containKeys(word[i]))
            {
                dummy->put(word[i], new Node());
            }
            dummy = dummy->get(word[i]);
        }
        dummy->setEnd();
    }

    bool isComplete(string word)
    {
        Node *dummy = root;

        for (size_t i = 0; i < word.size(); i++)
        {
            if (!dummy->containKeys(word[i]))
            {
                return false;
            }
            else
            {
                dummy = dummy->get(word[i]);
                if (!dummy->getEnd())
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    Node *root;
};

string completeString(int n, vector<string> &a)
{
    Trie t;
    for (auto &&i : a)
    {
        t.insert(i);
    }

    string ans = "";
    for (auto &&it : a)
    {
        if ((t.isComplete(it)) && (it.size() > ans.size()))
        {
            ans = it;
        }
        else if ((t.isComplete(it)) && (it.size() == ans.size()) && (it < ans))
        {
            ans = it;
        }
    }

    if (ans.empty())
    {
        return "None";
    }
    return ans;
}

int main()
{
    vector<string> keys = {"a", "ab", "abc", "abcd", "abcdef"};
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie root;

    cout << completeString(n, keys) << endl;
    return 0;
}