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

    void setPrefix()
    {
        ++countPrefix;
    }

    void setEnd()
    {
        ++countWord;
    }

    int getEnd()
    {
        return countWord;
    }

    int getPrefix()
    {
        return countPrefix;
    }

    void erasePrefix()
    {
        --countPrefix;
    }

    void eraseEnd()
    {
        --countWord;
    }

private:
    Node *links[26];
    int countPrefix = 0;
    int countWord = 0;
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
            dummy->setPrefix();
        }
        dummy->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *dummy = root;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (!dummy->containKeys(word[i]))
            {
                return 0;
            }
            dummy = dummy->get(word[i]);
        }
        return dummy->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *dummy = root;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (!dummy->containKeys(word[i]))
            {
                return 0;
            }
            dummy = dummy->get(word[i]);
        }
        return dummy->getPrefix();
    }

    void erase(string &word)
    {
        Node *dummy = root;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (dummy->containKeys(word[i]))
            {
                dummy = dummy->get(word[i]);
                dummy->erasePrefix();
            }
            else
            {
                return;
            }
        }
        dummy->eraseEnd();
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

    // cout << root_ref->countWordsStartingWith("the") << endl;
    // cout << root_ref->countWordsStartingWith("fgh") << endl;
    // cout << root_ref->countWordsEqualTo("the") << endl;
    // cout << root_ref->countWordsEqualTo("their") << endl;
    // cout << root_ref->countWordsEqualTo("gye") << endl;
    // root_ref->erase("bye");
    // cout << root_ref->countWordsEqualTo("bye") << endl;

    return 0;
}