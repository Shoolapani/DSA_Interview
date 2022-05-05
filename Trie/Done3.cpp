#include <bits/stdc++.h>
using namespace std;

// O(n) *O(LenOfString)
class Node
{
public:
    Node *link[26];
    bool flag = false;

    bool ifContainKey(char c);
    void put(char c, Node *node);
    Node *get(char c);

    void setEnd();
    bool isEnd();
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string &word);
    bool checkIfPrefixExists(string word);

private:
    Node *root;
};

// Node
bool Node::ifContainKey(char c)
{
    return (link[c - 'a'] != NULL);
}

void Node::put(char c, Node *node)
{
    link[c - 'a'] = node;
}

Node *Node ::get(char c)
{
    return link[c - 'a'];
}

void Node::setEnd()
{
    flag = true;
}

bool Node::isEnd()
{
    return flag;
}

// Trie Utility
void Trie::insert(string &word)
{
    Node *dummy = root;
    for (size_t i = 0; i < word.size(); i++)
    {
        if (!dummy->ifContainKey(word[i]))
        {
            dummy->put(word[i], new Node());
        }
        dummy = dummy->get(word[i]);
    }
    dummy->setEnd();
}

bool Trie::checkIfPrefixExists(string word)
{
    Node *dummy = root;
    for (size_t i = 0; i < word.size(); i++)
    {
        if (dummy->ifContainKey(word[i]))
        {
            dummy = dummy->get(word[i]);
            if (dummy->isEnd() == false)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

string completeString(int n, vector<string> &a)
{
    Trie t;
    string longest = "";
    for (auto &&it : a)
    {
        t.insert(it);
    }

    for (auto &&it : a)
    {
        if (t.checkIfPrefixExists(it))
        {
            if (longest.size() < it.size())
            {
                longest = it;
            }

            if ((longest.size() == it.size()) && (it < longest))
            {
                longest = it;
            }
        }
    }

    if (longest.empty())
    {
        return "None";
    }

    return longest;
}

int main()
{
    vector<string> keys = {"a","ab","abc","abcd","abcdef"};
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie root;

    cout << completeString(n, keys) << endl;
    return 0;
}