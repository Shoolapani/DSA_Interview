#include <bits/stdc++.h>
using namespace std;

class LRUCache;

class Node
{
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key_=0, int val_=0)
    {
        key = key_;
        val = val_;
        next = NULL;
        prev = NULL;
    }
    friend class LRUCache;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (uMap.find(key) == uMap.end())
        {
            return -1;
        }
        Node *resNode = uMap[key];
        int ans = resNode->val;
        uMap.erase(key);
        deleteNode(resNode);
        addNode(resNode);
        uMap[key] = head->next;
        return ans;
    }

    void put(int key, int value)
    {
        if (uMap.find(key) != uMap.end())
        {
            Node *existingNode = uMap[key];
            uMap.erase(key);
            deleteNode(existingNode);
        }
        if (uMap.size() == cap)
        {
            uMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        uMap[key] = head->next;
    }

private:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> uMap;

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *deleteNode)
    {
        Node *delPrev = deleteNode->prev;
        Node *delNext = deleteNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
};

int main()
{
    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 1);
    cout << l.get(2) << endl;
    l.put(4, 6);
    cout << l.get(4) << endl;
    cout << l.get(-1) << endl;
    return 0;
}