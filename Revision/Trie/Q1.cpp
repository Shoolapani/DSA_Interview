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

    bool isEnd()
    {
        return flag;
    }

private:
    Node *links[26];
    bool flag = 0;
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
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

    bool search(string word)
    {
        Node *dummy = root;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (!dummy->containKeys(word[i]))
            {
                return false;
            }
            dummy = dummy->get(word[i]);
        }

        if (dummy->isEnd() == false)
        {
            return false;
        }

        return true;
    }

    bool startsWith(string prefix)
    {
        Node *dummy = root;
        for (size_t i = 0; i < prefix.size(); i++)
        {
            if (!dummy->containKeys(prefix[i]))
            {
                return false;
            }
            dummy = dummy->get(prefix[i]);
        }
        return true;
    }

private:
    Node *root;
};

int main()
{
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie *root_ref = new Trie();

    // Construct trie
    for (int i = 0; i < n; i++)
        root_ref->insert(keys[i]);

    // Search for different keys
    root_ref->search("the") ? cout << "Yes\n" : cout << "No\n";
    root_ref->search("these") ? cout << "Yes\n" : cout << "No\n";
    root_ref->search("their") ? cout << "Yes\n" : cout << "No\n";
    root_ref->search("thaw") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}