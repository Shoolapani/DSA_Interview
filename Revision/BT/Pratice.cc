#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if ((head == NULL) || (head->next == NULL))
    {
        return NULL;
    }
    ListNode *fast = head;
    ListNode *slow = head;

    while ((fast->next) && (fast->next->next))
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return slow;
}

int main()
{
    return 0;
}