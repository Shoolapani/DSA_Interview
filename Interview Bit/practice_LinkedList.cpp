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

//  Palindrome Linked List
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    ListNode *curr = nullptr, *prev = nullptr;

    if ((head == NULL) || (head->next == nullptr))
    {
        return 1;
    }

    // find the middle node
    while ((fast->next != nullptr) && (fast->next->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next->next;
    curr = slow->next;
    slow->next = nullptr;
    slow = head;

    while ((curr->next != nullptr))
    {
        curr->next = prev;
        prev = curr;
        curr = fast;
        fast = fast->next;
    }
    curr->next = prev;

    while ((curr != nullptr) && (slow != nullptr))
    {
        if (curr->val != slow->val)
        {
            return 0;
        }
        curr = curr->next;
        slow = slow->next;
    }

    return 1;
}

// Rotate List
ListNode *rotateRight(ListNode *head, int k)
{
    int len = 1;
    ListNode *temp = head;

    while (temp->next != nullptr)
    {
        ++len;
        temp = temp->next;
    }

    temp->next = head;
    k = k % len;
    int end = len - k;

    while (end--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
}

// Swap List Nodes in pairs
ListNode *reverseKGroupLL(ListNode *head, int k)
{
    if ((k == 1) || (head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    int len = 0;
    ListNode *dummy = new ListNode(0), *prev = dummy;
    dummy->next = head;

    while (prev->next != nullptr)
    {
        ++len;
        prev = prev->next;
    }
    prev = dummy;
    ListNode *curr = dummy->next, *nex = curr->next;

    while (len >= k)
    {
        curr = prev->next;
        nex = curr->next;
        for (size_t i = 1; i < k; i++)
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

ListNode *SolutionswapPairs(ListNode *head)
{
    return reverseKGroupLL(head, 2);
}

// Kth Node From Middle
int solveNode(ListNode *head, int B)
{
    ListNode *prev = head;

    int len = 0;

    while (prev->next != nullptr)
    {
        ++len;
        prev = prev->next;
    }

    prev = head;
    if ((B > len) || (B > ((len / 2) + 1)))
    {
        return -1;
    }

    int mid = (len / 2) + 1;
    mid = mid - B;

    while ((mid--) && (prev != nullptr))
    {
        prev = prev->next;
    }

    return prev->val;
}

// Remove Duplicates from Sorted List II
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0), *prev = dummy;
    dummy->next = head;

    while (head != nullptr)
    {
        if ((head->next != nullptr) && (head->val == head->next->val))
        {
            while ((head->next != nullptr) && (head->val == head->next->val))
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
}

// Remove Duplicates from Sorted List
ListNode *deleteDuplicates1(ListNode *head)
{
    ListNode *dummy = new ListNode(0), *prev = head;
    dummy->next = head;

    while (head != nullptr)
    {
        if (prev->val != head->val)
        {
            prev->next = head;
            prev = prev->next;
        }
        else
        {
            while ((head->next != nullptr) && (prev->val == head->val))
            {
                head = head->next;
            }
            if ((head->next == nullptr) && (prev->val == head->val))
            {
                prev->next = nullptr;
                head = head->next;
                continue;
            }
            prev->next = head;
            prev = prev->next;
        }
        head = head->next;
    }

    return dummy->next;
}

// Remove Duplicates from Sorted List
ListNode *deleteDuplicates2(ListNode *head)
{
    ListNode *curr = head;

    while (curr != nullptr)
    {
        while ((curr->next) && (curr->val == curr->next->val))
        {
            curr = curr->next->next;
        }
        curr = curr->next;
    }

    return head;
}

// Remove Nth Node from List End Interview Bit
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0), *slow = dummy, *fast = dummy;
    dummy->next = head;

    for (size_t i = 0; i < n; i++)
    {
        fast = fast->next;
        if (!fast)
        {
            break;
        }
    }
    if (!fast)
    {
        dummy = head->next;
        return dummy;
    }

    while ((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return dummy->next;
}

// Merge Two Sorted Lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if ((l1 == NULL))
    {
        return l2;
    }
    if ((l2 == NULL))
    {
        return l1;
    }

    if (l1->val > l2->val)
    {
        swap(l2, l1);
    }

    ListNode *prev = nullptr, *head = l1;

    while ((l1) && (l2))
    {
        if (l1->val <= l2->val)
        {
            prev = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            swap(l1, l2);
        }
    }

    if (l2)
    {
        prev->next = l2;
    }
    else
    {
        prev->next = l1;
    }
    return head;
}

// Partition List
ListNode *partition(ListNode *A, int B)
{
    vector<int> ds1, ds2;
    ListNode *temp = A;

    while (temp != nullptr)
    {
        if (temp->val < B)
        {
            ds1.push_back(temp->val);
        }
        else
        {
            ds2.push_back(temp->val);
        }
        temp = temp->next;
    }
    temp = A;
    int ind = 0;
    int flag = 0;
    while ((flag < ds1.size()) && (temp != nullptr))
    {
        temp->val = ds1[flag++];
        temp = temp->next;
    }
    while (ind < ds2.size() && (temp != nullptr))
    {
        temp->val = ds2[ind++];
        temp = temp->next;
    }

    return A;
}

// Reverse Link List II
ListNode *reverseBetween(ListNode *A, int B, int C)
{
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *partition(ListNode *A, int B)
{
    if (!A)
        return A;

    ListNode *fake1 = new ListNode(0);
    ListNode *fake2 = new ListNode(0);
    fake1->next = A;

    ListNode *p = A, *prev = fake1, *p2 = fake2;

    while (p)
    {
        if (p->val < B)
        {
            p = p->next;
            prev = prev->next;
        }
        else
        {
            p2->next = p;
            prev->next = p->next;

            p = prev->next;
            p2 = p2->next;
        }
    }
    p2->next = NULL;
    prev->next = fake2->next;

    return fake1->next;
    ListNode *i, *j, *toDelNode;
    int temp;
    i = A, j = A;
    while (i && j && j->next)
    {
        if (j->next->val < B)
        {
            toDelNode = j->next;
            j->next = toDelNode->next;
            toDelNode->next = i;
            i->next = toDelNode;
            i = i->next;
        }
        if (j)
        {
            j = j->next;
        }
    }
    return A;
}

// Insertion Sort List
// O(N) O(N)
ListNode *insertionSortList1(ListNode *A)
{
    vector<int> ds1;
    ListNode *temp = A;

    while (temp != nullptr)
    {
        ds1.push_back(temp->val);
        temp = temp->next;
    }

    temp = A;
    sort(ds1.begin(), ds1.end());

    int ind = 0;
    while (temp != nullptr)
    {
        temp->val = ds1[ind++];
        temp = temp->next;
    }

    return A;
}

// O(N^2) O(N)
ListNode *insertionSortList2(ListNode *head)
{
    ListNode *dummy = new ListNode(-1), *prev = head;
    dummy->next = head;

    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    ListNode *curr = head->next;
    while (curr)
    {
        if (curr->val >= prev->val)
        {
            prev = curr;
            curr = curr->next;
            continue;
        }

        ListNode *temp = dummy;
        while ((temp->next != nullptr) && (curr->val > temp->next->val))
        {
            temp = temp->next;
        }

        prev->next = prev->next->next;
        curr->next = temp->next;
        temp->next = curr;
        curr = prev->next;
    }

    return dummy->next;
}

// Sort List
// O(nlogn) Merge Sort

ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }

    if (head2 == nullptr)
    {
        return head1;
    }

    if (head1->val > head2->val)
    {
        swap(head1, head2);
    }

    ListNode *prev = nullptr, *headPtr = head1;
    while ((head1) && (head2))
    {
        if (head1->val <= head2->val)
        {
            prev = head1;
            head1 = head1->next;
        }
        else
        {
            prev->next = head2;
            swap(head2, head1);
        }
    }

    if (head2)
    {
        prev->next = head2;
    }
    else
    {
        prev->next = head1;
    }

    return headPtr;
}

ListNode *sortList(ListNode *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    ListNode *slow = head, *fast = head, *temp = slow;

    while ((fast->next) && (fast->next->next))
    {
        slow = slow->next;
        fast = fast->next;
    }
    temp = slow->next;
    slow->next = nullptr;
    ListNode *left = head;
    left = sortList(left);
    temp = sortList(temp);

    return merge(left, temp);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* See http://geeksforgeeks.org/?p=3622 for details of this
   function */
ListNode *SortedMerge(ListNode *a, ListNode *b)
{
    ListNode *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

ListNode *sortList(ListNode *A)
{
    if (!A || !A->next)
        return A;

    ListNode *head, *a, *b, *slow, *fast, *ret;
    head = A;

    slow = head;
    fast = head->next;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    a = head;
    b = slow->next;
    slow->next = NULL;

    a = sortList(a);
    b = sortList(b);

    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }
    return SortedMerge(a, b);
}

// Reverse Alternate K Nodes
ListNode *solveAlternate(ListNode *A, int k)
{
    if ((k == 1) || (A == nullptr) || (A->next == nullptr))
    {
        return A;
    }

    ListNode *temp = new ListNode(0), *dummy = temp, *prev = temp, *curr = A, *nex = A->next;
    temp->next = A;
    int len = 0;
    bool flag = 1;

    while (temp->next != nullptr)
    {
        ++len;
        temp = temp->next;
    }
    temp = A;

    while (len >= k)
    {
        if (flag)
        {
            curr = prev->next;
            nex = curr->next;

            for (size_t i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len -= k;
            flag = 0;
        }
        else
        {
            int val = k;
            while ((val--) && (prev != nullptr))
            {
                prev = prev->next;
            }
            len -= k;
            flag = 1;
        }
    }

    return dummy->next;
}

// Reverse Link List II
ListNode *reverseBetween(ListNode *A, int B, int C)
{
    int len = 1;
    if ((B == C) || (A == nullptr) || (A->next == nullptr))
    {
        return A;
    }

    ListNode *temp = A, *dummy = A;
    vector<int> ds;
    int val = B;

    while ((temp != nullptr) && (len < B))
    {
        temp = temp->next;
        ++len;
    }
    dummy = temp;
    while ((temp != nullptr) && (val >= B) && (val <= C))
    {
        ds.push_back(temp->val);
        temp = temp->next;
        ++val;
    }

    temp = dummy;
    reverse(ds.begin(), ds.end());
    val = 0;
    while ((temp != nullptr) && (val < ds.size()))
    {
        temp->val = ds[val++];
        temp = temp->next;
    }

    return A;
}

int main()
{

    return 0;
}