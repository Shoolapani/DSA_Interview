#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

ListNode *reverseList(ListNode *A)
{
    ListNode *prev = nullptr, *curr = A, *nextNode = A;
    if (A->next == nullptr)
    {
        return A;
    }
    nextNode = A->next;

    while (nextNode != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    curr->next = prev;
    prev = curr;
    curr = nextNode;

    return prev;
}

ListNode *getIntersectionNode(ListNode *A, ListNode *B)
{
    ListNode *head1 = A, *head2 = B;

    while ((head1 != nullptr) || (head2 != nullptr))
    {
        if (head1 == head2)
        {
            return head1;
        }
        else
        {
            head2 = (head2 == nullptr) ? (A) : (head2->next);
            head1 = (head1 == nullptr) ? (B) : (head1->next);
        }
    }

    return nullptr;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    long long int carry = 0, sum = 0;
    ListNode *sumNode = new ListNode(0), *head = sumNode;

    while ((l1 != nullptr) || (l2 != nullptr) || (carry))
    {
        sum = 0;
        if (l1 != nullptr)
        {
            sum += (l1->val);
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            sum += (l2->val);
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        sumNode->next = new ListNode(sum);
        sumNode = sumNode->next;
    }

    return head->next;
}

// Linked List Cycle
bool hasCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    if ((head == nullptr) || (head->next == nullptr) || (head->next->next == nullptr))
    {
        return 0;
    }
    fast = head->next;

    while ((fast->next != nullptr) && (fast->next->next != nullptr))
    {
        if (fast == slow)
        {
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }

    return 0;
}

// List Cycle
ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    bool flag = 0;
    if ((head == nullptr) || (head->next == nullptr) || (head->next->next == nullptr))
    {
        return nullptr;
    }
    // fast = head->next;

    while ((fast->next != nullptr) && (fast->next->next != nullptr))
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
    return nullptr;
}

ListNode *solve(ListNode *A)
{
    vector<int> ds;
    ListNode *dummy = A, *newNode = A, *newHead = newNode;
    int len = 0, ind = 0;
    while (dummy != NULL)
    {
        ++len;
        if ((len & 1) == 0)
        {
            ds.push_back(dummy->val);
        }
        dummy = dummy->next;
    }

    reverse(ds.begin(), ds.end());

    for (size_t i = 1; i <= len; i++)
    {
        if ((i & 1) == 0)
        {
            newNode->val = ds[ind++];
        }
        newNode = newNode->next;
    }

    return newHead;
}

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

// Flattening a Linked List
// O(N)
Node *merge(Node *a, Node *b)
{
    Node *dummy = new Node(0);
    Node *res = dummy;

    while ((a != nullptr) && (b != nullptr))
    {
        if (a->data < b->data)
        {
            dummy->bottom = a;
            dummy = dummy->bottom;
            a = a->bottom;
        }
        else
        {
            dummy->bottom = b;
            dummy = dummy->bottom;
            b = b->bottom;
        }
    }

    if (a)
    {
        dummy->bottom = a;
    }
    else
    {
        dummy->bottom = b;
    }

    return res->bottom;
}

Node *flatten(Node *root)
{
    if ((root == nullptr) || (root->next == nullptr))
    {
        return root;
    }

    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}



int main()
{
    return 0;
}