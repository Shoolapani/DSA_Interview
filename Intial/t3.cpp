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

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    unordered_map<int, int> matchMap;
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> ds2;

    for (size_t i = 0; i < matches.size(); i++)
    {
        matchMap[matches[i][0]]++;
        matchMap[matches[i][1]]--;
    }

    for (auto it = matchMap.begin(); it != matchMap.end(); it++)
    {
        if (it->first >= 1)
        {
            ds.push_back(it->first);
        }
        if (it->first >= 1)
        {
            ds.push_back(it->first);
        }
    }
}

int convertTime(string current, string correct)
{
    int ans = 0;
    vector<string> tokens1, tokens2;
    stringstream check1(current);
    stringstream check2(correct);
    string intermediate, intermediate2;

    while (getline(check1, intermediate, ':'))
    {
        tokens1.push_back(intermediate);
    }

    while (getline(check2, intermediate2, ':'))
    {
        tokens2.push_back(intermediate2);
    }

    int currF = stoi(tokens1[0]);
    int corrF = stoi(tokens2[0]);
    ans += corrF - currF;

    int currS = stoi(tokens1[1]);
    int corrS = stoi(tokens2[1]);

    currS = corrS - currS;

    while (currF % 15 >= currF)
    {
        ans += currF / 15;
        currF = currF / 15;
    }

    while (currF % 5 >= currF)
    {
        ans += currF / 5;
        currF = currF / 5;
    }

    ans += currF;

    return ans;
}

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