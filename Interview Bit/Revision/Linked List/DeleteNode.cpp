#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val = 0, ListNode *next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};

void makeNewNode(int val, ListNode *&head)
{
    ListNode *newNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

void printLL(ListNode *head)
{
    while (head->next != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << " NULL" << endl;
}

int main()
{
    ListNode *head = nullptr;
    makeNewNode(2, head);
    makeNewNode(3, head);
    makeNewNode(4, head);
    deleteNode(head->next);
    printLL(head);

    return 0;
}