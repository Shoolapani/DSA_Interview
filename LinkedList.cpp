#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int d;
    Node *next;

    Node(int d = 0, Node *n = nullptr)
    {
        this->d = d;
        this->next = n;
    }
};

void push(Node *&head_ref, int nd)
{
    Node *newNode = new Node(nd, head_ref);
    (head_ref) = newNode;
    return;
}

void append(Node *&head_ref, int nd)
{
    Node *newNode = new Node(nd);

    if (head_ref == nullptr)
    {
        (head_ref) = newNode;
        return;
    }
    Node *last = head_ref;

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}

void InsertBetween(Node *node, int nd)
{
    if (node == NULL)
    {
        return;
    }
    Node *newNode = new Node(nd, node->next);
    node->next = newNode;
    return;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->d;
        node = node->next;
    }
}

Node *middleNode(Node *head)
{
    Node *slow = head, *fast = head;

    while ((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *newNode = nullptr, *head = nullptr;

    if (list1->d <= list2->d)
    {
        head = list1;
    }
    else
    {
        head = list2;
    }

    while ((list1 != NULL) && (list2 != NULL))
    {
        if (list1->d <= list2->d)
        {
            newNode = list1->next;
            list1->next = list2;
            list1 = newNode;
        }
        else
        {
            newNode = list2->next;
            list2->next = list1;
            list2 = newNode;
        }
    }

    while (list1->next != NULL)
    {
        newNode = list1->next;
        list1->next = list2;
        list1 = newNode;
    }

    while (!list2)
    {
        newNode = list2->next;
        list2->next = list1;
        list2 = newNode;
    }

    return head;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *d = new ListNode(), *dd = d;

    while ((list1 != NULL) && (list2 != NULL))
    {
        if (list1->val <= list2->val)
        {
            d->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            d->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        d = d->next;
    }
    while (list1 != NULL)
    {
        d->next = new ListNode(list1->val);
        list1 = list1->next;
        d = d->next;
    }

    while (list2)
    {
        d->next = new ListNode(list2->val);
        list2 = list2->next;
        d = d->next;
    }

    return dd->next;
}

ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2)
{

    if ((list1 == NULL))
    {
        return list2;
    }
    if ((list2 == NULL))
    {
        return list1;
    }

    ListNode *res = nullptr, *temp = nullptr;
    (list1->val <= list2->val) ? (res = list1) : (swap(list1, list2), res = list1);

    while ((list1) && (list2 != NULL))
    {
        if (list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
            swap(list1, list2);
        }
    }

    temp->next = list2;
    return res;
}

int main()
{
    Node *head = NULL;
    append(head, 2);
    push(head, 1);

    Node *head2 = head->next;
    InsertBetween(head2, 3);
    append(head, 4);
    printList(head);
    cout << endl;
    // printList(removeNthFromEnd(head, 2));
    // Node *head3 = NULL;
    // append(head3, 5);
    // push(head3, 3);
    // push(head3, 1);
    // printList(head3);
    // cout << endl;

    return 0;
}