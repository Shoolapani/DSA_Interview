#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
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

// O(N) O(N)
Node *copyRandomList1(Node *head)
{
    unordered_map<Node *, Node *> uMap;
    Node *temp = head;

    while (temp != nullptr)
    {
        uMap[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;

    while (temp != nullptr)
    {
        uMap[temp]->next = uMap[temp->next];
        uMap[temp]->random = uMap[temp->random];
        temp = temp->next;
    }

    return uMap[head];
}

// O(N) O(1)
Node *copyRandomList2(Node *head)
{
    Node *iter = head;
    Node *front = head;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != NULL)
    {
        front = iter->next;

        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;

        iter = front;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
        {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;

    while (iter != NULL)
    {
        front = iter->next->next;

        // extract the copy
        copy->next = iter->next;

        // restore the original list
        iter->next = front;

        copy = copy->next;
        iter = front;
    }

    return pseudoHead->next;
}

int main()
{
    return 0;
}