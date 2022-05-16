#include <bits/stdc++.h>
using namespace std;

class LFUCache;
class List;

class Node
{
    int key;
    int countFreq;
    int value;
    Node *next;
    Node *prev;

    Node(int key = -1, int value = -1)
    {
        this->key = key;
        this->value = value;
        this->countFreq = 1;
        next = NULL;
        prev = NULL;
    }
    
    friend class LFUCache;
    friend class List;
};

class List
{
public:
    int size;
    Node *head;
    Node *tail;

    void addNode(Node *newNode);
    void deleteNode(Node *deleteNode);
    List()
    {
        head = new Node();
        tail = new Node();
        tail->prev = head;
        head->next = tail;
        size = 0;
    }
};

class LFUCache
{
public:
    LFUCache(int capacity)
    {
        cap = capacity;
        minFreq = 1;
        curSize = 0;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (curSize == 0)
        {
            return;
        }

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == cap)
            {
                List *listNOde = listFreqMap[minFreq];
                keyNode.erase(listNOde->tail->prev->key);
                listFreqMap[minFreq]->deleteNode(listNOde->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (listFreqMap.find(minFreq) != listFreqMap.end())
            {
                listFreq = listFreqMap[minFreq];
            }
            Node *newNode = new Node(key, value);
            listFreq->addNode(newNode);
            keyNode[key] = newNode;
            listFreqMap[minFreq] = listFreq;
        }
    }

private:
    unordered_map<int, List *> listFreqMap;
    unordered_map<int, Node *> keyNode;
    int cap;
    int minFreq;
    int curSize;

    void updateFreqListMap(Node *node);
};

void List::addNode(Node *newNode)
{
    Node *temp = head->next;
    newNode->prev = head;
    newNode->next = temp;
    head->next = newNode;
    temp->prev = newNode;
    ++size;
}

void List::deleteNode(Node *deleteNode)
{
    Node *delPrev = deleteNode->prev;
    Node *delNext = deleteNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
    --size;
}

void LFUCache::updateFreqListMap(Node *node)
{
    keyNode.erase(node->key);
    listFreqMap[node->countFreq]->deleteNode(node);

    if ((node->countFreq == minFreq) && (listFreqMap[node->countFreq]->size == 0))
    {
        minFreq++;
    }

    List *newHigherFreq = new List();
    if (listFreqMap.find(node->countFreq + 1) != listFreqMap.end())
    {
        newHigherFreq = listFreqMap[node->countFreq + 1];
    }
    node->countFreq += 1;
    newHigherFreq->addNode(node);
    listFreqMap[node->countFreq] = newHigherFreq;
    keyNode[node->key] = node;
}




int main()
{
    return 0;
}