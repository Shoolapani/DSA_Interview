#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class Node
{
public:
    Node *children[ALPHABET_SIZE];
    bool flag = false;

    // will tell if specific key is present in specific children
    bool isContainKey(char c)
    {
        return (children[c - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        children[ch - 'a'] = node;
    }

    // getting desired location address;
    Node *get(char ch)
    {
        return children[ch - 'a'];
    }

    // For setting flag as  true;
    void setEnd()
    {
        flag = true;
    }

    // Finding that this children is end or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    // For Inerting children in the trie;
    void insert(string s)
    {
        Node *dummy = root;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (dummy->isContainKey(s[i]) == false)
            {
                dummy->put(s[i], new Node());
            }
            dummy = dummy->get(s[i]);
        }
        dummy->setEnd();
    }

    // For searching a string in trie;
    bool search(string word)
    {
        Node *dummy = root;
        for (size_t i = 0; i < word.length(); i++)
        {
            if (!dummy->isContainKey(word[i]))
            {
                return false;
            }
            dummy = dummy->get(word[i]);
        }
        // find if this is end is or not (Prefix may be)
        if (dummy->isEnd())
        {
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *dummy = root;
        for (size_t i = 0; i < prefix.size(); i++)
        {
            if (!dummy->isContainKey(prefix[i]))
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