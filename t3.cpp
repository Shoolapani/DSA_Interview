#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> hash;
    Node *temp = head;

    while (temp)
    {
        hash.insert({temp, new Node(temp->val)});
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        hash[temp]->next = hash[temp->next];
        hash[temp]->random = hash[temp->random];
        temp = temp->next;
    }

    return hash[head];
}

Node *copyRandomList2(Node *head)
{
    Node *temp = head;
    Node *newNode = new Node(head->val), *head2 = newNode;

    while (temp)
    {
        newNode->val = temp->val;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode = new Node(0);
        temp = temp->next->next;
    }
    temp = head;
    if (temp == NULL)
    {
        return temp;
    }

    if (temp->next == NULL)
    {
        return newNode;
    }

    newNode = temp->next;
    while (newNode->next != nullptr)
    {
        if (temp->random == NULL)
        {
            newNode->random = NULL;
        }
        else if (temp->random == temp)
        {
            newNode->random = newNode;
        }
        else
        {
            newNode->random = temp->random->next;
        }
        temp = temp->next->next;
        newNode = newNode->next->next;
    }
    newNode->next = nullptr;

    // last step
    temp = head;
    newNode = temp->next;
    while (temp->next != nullptr)
    {
        temp->next = temp->next->next;
    }
    temp->next = nullptr;

    while (newNode->next != nullptr)
    {
        newNode->next = newNode->next->next;
    }
    newNode->next = nullptr;
    return head2;
}