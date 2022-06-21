//  😢😢Reverse Nodes in k-Group
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    if ((k == 1) || (head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    int len = 0;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = dummy, *prev = dummy, *nex = dummy;

    while ((curr->next))
    {
        ++len;
        curr = curr->next;
    }

    while (len >= k)
    {
        curr = prev->next;
        nex = curr->next;
        for (size_t i = 0; i < k; i++)
        {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        len -= k;
    }

    return dummy->next;
}

int main()
{
    return 0;
}