#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class Node
{
public:
    Node *children[ALPHABET_SIZE];
    int cntEndWith = 0;
    int cntPrefix = 0;

    // Utility Function
    bool ifContainKey(char c);
    void put(char c, Node *node);

    Node *get(char c)
    {
        return children[c - 'a'];
    }

    void increasePrefix();
    void increaseEnd();
    void reducePrefix();
    void deleteEnd();

    int getEnd();
    int getPrefix();
};

class Trie
{
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string s);
    int countWordsEqualTo(string s);
    int countWordsStartingWith(string s);
    void erase(string s);

private:
    Node *root;
};

bool Node::ifContainKey(char c)
{
    return (children[c - 'a'] != NULL);
}

void Node::put(char c, Node *node)
{
    children[c - 'a'] = node;
}

void Node::increasePrefix()
{
    cntPrefix++;
}

void Node::increaseEnd()
{
    ++cntEndWith;
}

void Node::reducePrefix()
{
    --cntPrefix;
}

void Node::deleteEnd()
{
    --cntEndWith;
}

int Node::getEnd()
{
    return this->cntEndWith;
}

int Node::getPrefix()
{
    return this->cntPrefix;
}

void Trie::insert(string s)
{
    Node *dummy = root;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!dummy->ifContainKey(s[i]))
        {
            dummy->put(s[i], new Node());
        }
        dummy = dummy->get(s[i]);
        dummy->increasePrefix();
    }
    dummy->increaseEnd();
}

int Trie::countWordsEqualTo(string s)
{
    Node *dummy = root;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (dummy->ifContainKey(s[i]))
        {
            dummy = dummy->get(s[i]);
        }
        else
        {
            return 0;
        }
    }
    return dummy->getEnd();
}

int Trie ::countWordsStartingWith(string s)
{
    Node *dummy = root;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (dummy->ifContainKey(s[i]))
        {
            dummy = dummy->get(s[i]);
        }
        else
        {
            return 0;
        }
    }
    return dummy->getPrefix();
}

void Trie::erase(string s)
{
    Node *dummy = root;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (dummy->ifContainKey(s[i]))
        {
            dummy = dummy->get(s[i]);
            dummy->reducePrefix();
        }
        else
        {
            return;
        }
    }
    dummy->deleteEnd();
}

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

    cout << root_ref->countWordsStartingWith("the") << endl;
    cout << root_ref->countWordsStartingWith("fgh") << endl;
    cout << root_ref->countWordsEqualTo("the") << endl;
    cout << root_ref->countWordsEqualTo("their") << endl;
    cout << root_ref->countWordsEqualTo("gye") << endl;
    root_ref->erase("bye");
    cout << root_ref->countWordsEqualTo("bye") << endl;

    return 0;
}