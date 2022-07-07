#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std::chrono;
using namespace std;

// 225. Implement Stack using Queues
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (size_t i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        int val = q.front();
        return val;
    }

    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};

// Implement Queue using Stacks
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int size = s1.size();
        stack<int> s2;
        for (size_t i = 1; i < size; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }

        int val = s1.top();
        s1.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return val;
    }

    int peek()
    {
        stack<int> s2;
        int size = s1.size();
        s2 = s1;
        for (size_t i = 1; i < size; i++)
        {
            s2.pop();
        }

        int val = s2.top();
        return val;
    }

    bool empty()
    {
        return s1.empty();
    }

private:
    stack<int> s1;
};

// Valid Parentheses
// Generate all Parentheses
bool isValid(string s)
{
    stack<char> s1;

    for (size_t i = 0; i < s.length(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            s1.push(s[i]);
        }
        else
        {
            if (s1.empty() or (s1.top() == '(' and s[i] != ')') or (s1.top() == '{' and s[i] != '}') or (s1.top() == '[' and s[i] != ']'))
            {
                return 0;
            }
            s1.pop();
        }
    }
    return s1.empty();
}

// Next Greater Element I
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> uMap;
    stack<int> st;
    vector<int> ans;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while ((!st.empty()) && (nums2[i] > st.top()))
        {
            st.pop();
        }

        if (st.empty())
        {
            uMap[nums2[i]] = -1;
        }
        else
        {
            uMap[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }

    for (auto &&i : nums1)
    {
        if (uMap.count(i))
        {
            ans.push_back(uMap[i]);
        }
    }

    return ans;
}

// NEXT GREATER
// Your submission failed for the following input
// A : [ 34, 35, 27, 42, 5, 28, 39, 20, 28 ]

// The expected return value:
// 35 42 42 -1 28 39 -1 28 -1
// Your function returned the following:
// 27 27 5 5 -1 20 20 -1 -1
vector<int> nextGreater(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while ((!s.empty()) && (nums[i] >= s.top()))
        {
            s.pop();
        }

        ans[i] = (s.empty() ? (-1) : (s.top()));
        s.push(nums[i]);
    }
    return ans;
}

class MinStack
{
public:
    MinStack()
    {
        minVal = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            minVal = val;
        }
        else
        {
            minVal = min(val, st.top().second);
        }
        st.push({val, minVal});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
    int minVal;
};

class MinStack2
{
public:
    MinStack2()
    {
        while (st.empty() == false)
            st.pop();
        minVal = INT_MAX;
    }

    void push(int val)
    {
        long long int ele = val;
        if (st.empty())
        {
            minVal = val;
            st.push(val);
        }
        else
        {
            if (val < minVal)
            {
                ele = (2 * val) - minVal;
                minVal = val;
            }
            st.push(ele);
        }
    }

    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = (2 * minVal) - (st.top());
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < minVal)
        {
            return minVal;
        }
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }

private:
    stack<int> st;
    long long int minVal;
};

// 71. Simplify Path
//  Not Working
// 😢😒🤦‍♂️ Loop lagao
// string simplifyPath1(string path)
// {
//     string ans = "/";

//     for (size_t i = 0; i < path.length(); i++)
//     {
//         if ((i == path.length() - 1) && (path[i] == '/'))
//         {
//             continue;
//         }
//         else if ((!ans.empty()) && (ans[ans.length() - 1] == '/') && (path[i] == '/'))
//         {
//             continue;
//         }
//         else if ((i + 1 < path.length()) && (ans.length() == 1) && (ans[ans.length() - 1] == '/') && (path[i] == '.') && (path[i + 1] == '.'))
//         {
//             if ((i + 2 < path.length()) && (path[i + 2] == '.'))
//             {
//                 i += 2;
//                 ans += "...";
//             }
//             else if ((i + 2 < path.length()) && (path[i + 2] != '/'))
//             {
//                 while ((i < path.length()) && (path[i] != '/'))
//                 {
//                     ans += path[i];
//                     i++;
//                 }
//                 --i;
//             }
//             else if ((i > 0) && (path[i - 1]) != '/')
//             {
//                 ans += "..";
//                 continue;
//             }
//             else
//                 continue;
//         }
//         else if ((i + 1 < path.length()) && (path[i] == '.') && (path[i + 1] == '.'))
//         {
//             if ((i + 2 < path.length()) && (path[i + 2] == '.'))
//             {
//                 i += 2;
//                 ans += "...";
//                 continue;
//             }
//             else if ((i + 2 < path.length()) && (path[i + 2] != '/'))
//             {
//                 while ((i < path.length()) && (path[i] != '/'))
//                 {
//                     ans += path[i++];
//                 }
//                 --i;
//             }
//             else if ((i > 0) && (path[i - 1]) != '/')
//             {
//                 ans += "..";
//                 continue;
//             }
//             else
//             {
//                 ans.pop_back();
//                 while (ans[ans.length() - 1] != '/')
//                 {
//                     ans.pop_back();
//                 }
//                 ans.pop_back();
//             }
//         }
//         else if (path[i] == '.')
//         {
//             if ((i + 1 < path.length()) && (path[i + 1] != '/'))
//             {
//                 while ((i < path.length()) && (path[i] != '/'))
//                 {
//                     ans += path[i++];
//                 }
//                 --i;
//             }
//             continue;
//         }
//         else
//         {
//             ans += path[i];
//         }
//     }
//     if ((ans.length() > 1) and (ans[ans.length() - 1] == '/'))
//     {
//         ans.pop_back();
//     }
//     return ans;
// }

string simplifyPath(string path)
{
    stringstream strStream(path);
    string ans = "", temp = "";
    vector<string> res;

    while (getline(strStream, temp, '/'))
    {
        if ((temp == "") or (temp == "."))
        {
            continue;
        }
        else if ((temp == "..") and (!res.empty()))
        {
            res.pop_back();
        }
        else if (temp != "..")
        {
            res.push_back(temp);
        }
    }

    if (res.size() == 0)
    {
        return "/";
    }

    for (auto &&it : res)
    {
        ans += "/" + it;
    }

    return ans;
}

// 239. Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if ((!dq.empty()) and (dq.front() == i - k))
        {
            dq.pop_front();
        }

        while ((!dq.empty()) and (nums[dq.back()] < nums[i]))
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= (k - 1))
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int _key = 0, int _value = 0)
        : key{_key}, value{_value}
    {
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (uMap.find(key) == uMap.end())
        {
            return -1;
        }
        int res = uMap[key]->value;
        Node *node = uMap[key];
        uMap.erase(key);
        deleteNode(node);
        addNode(node);
        uMap[node->key] = head->next;
        return res;
    }

    void put(int key, int value)
    {
        if ((uMap.find(key) != uMap.end()))
        {
            Node *existingNode = uMap[key];
            uMap.erase(key);
            deleteNode(existingNode);
        }
        if (uMap.size() == size)
        {
            uMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        uMap[key] = head->next;
    }

    ~LRUCache()
    {
        delete head;
        delete tail;
    }

private:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> uMap;
    int size;

    void addNode(Node *newNode);
    void deleteNode(Node *deleteNode);
};

void LRUCache::addNode(Node *newNode)
{
    Node *temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
}

void LRUCache::deleteNode(Node *deleteNode)
{
    Node *delPrevNode = deleteNode->prev;
    Node *delNextNode = deleteNode->next;
    delPrevNode->next = delNextNode;
    delNextNode->prev = delPrevNode;
}

// First non-repeating character in a stream of characters
// O(N^2)
string solveNonRepeating(string s)
{
    unordered_map<char, int> uMap;
    string ans = "";
    bool flag = 1;

    for (auto i = 0; i < s.length(); i++)
    {
        uMap[s[i]]++;
        flag = 1;
        for (size_t j = 0; j <= i; j++)
        {
            if (uMap[s[j]] == 1)
            {
                ans += s[j];
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ans += "#";
        }
    }

    return ans;
}

string solveNonRepeating1(string s)
{
    unordered_map<char, int> uMap;
    string ans = "";
    queue<char> q;

    for (auto i = 0; i < s.length(); i++)
    {
        uMap[s[i]]++;
        q.push(s[i]);
        while ((!q.empty()) && (uMap[q.front()] > 1))
        {
            q.pop();
        }

        if (q.empty())
        {
            ans += "#";
        }
        else
        {
            ans += q.front();
        }
    }

    return ans;
}

string solveNonRepeating2(string s)
{
    unordered_map<char, int> uMap;
    string ans = "";
    queue<char> q;

    for (auto i = 0; i < s.length(); i++)
    {
        uMap[s[i]]++;
        q.push(s[i]);
        while ((!q.empty()) && (uMap[q.front()] > 1))
        {
            q.pop();
        }

        if (q.empty())
        {
            ans += "#";
        }
        else
        {
            ans += q.front();
        }
    }

    return ans;
}

// Redundant Braces
int braces(string A)
{
    stack<char> st;

    for (size_t i = 0; i < A.length(); i++)
    {
        if (A[i] != ')')
        {
            if ((!isalpha(A[i])))
            {
                st.push(A[i]);
            }
        }
        else if ((A[i] == ')'))
        {
            if (st.top() == '(')
            {
                return 1;
            }
            while ((!st.empty()) and (st.top() != '('))
            {
                st.pop();
            }
            st.pop();
        }
    }

    return 0;
}

int evalRPN(vector<string> &A)
{
    stack<int> st;
    if (A.size() == 1)
    {
        return stoi(A[0]);
    }
    for (size_t i = 0; i < A.size(); i++)
    {
        if ((A[i] == "+") or (A[i] == "-") or (A[i] == "/") or (A[i] == "*"))
        {
            if ((A[i] == "-"))
            {
                int ans = 0;
                ans = st.top();
                st.pop();
                int count = 1;
                while ((!st.empty()) and (count--))
                {
                    ans = st.top() - ans;
                    st.pop();
                }
                st.push(ans);
            }
            else if ((A[i] == "+"))
            {
                int ans = 0;
                ans = st.top();
                st.pop();
                int count = 1;
                while ((!st.empty()) and (count--))
                {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.push(ans);
            }
            else if ((A[i] == "*"))
            {
                int ans = 0;
                ans = st.top();
                st.pop();
                int count = 1;
                while ((!st.empty()) and (count--))
                {
                    ans = st.top() * ans;
                    st.pop();
                }
                st.push(ans);
            }
            else
            {
                int ans = 0;
                ans = st.top();
                st.pop();
                int count = 1;
                while ((!st.empty()) and (count--))
                {
                    ans = st.top() / ans;
                    st.pop();
                }
                st.push(ans);
            }
        }
        else
        {
            st.push(stoi(A[i]));
        }
    }
    return st.top();
}

// MAXSPPROD
#define ll long long int
int maxSpecialProduct2(vector<int> &A)
{
    vector<ll> infixLarge(A.size(), 0), postFix(A.size(), 0);
    long long int ans = 0;
    stack<ll> st, st2;

    for (ll i = 0; i < A.size(); i++)
    {
        while ((!st.empty()) and (A[st.top()] <= A[i]))
        {
            st.pop();
        }
        if ((!st.empty()))
            infixLarge[i] = st.top();
        st.push(i);
    }

    for (ll i = A.size() - 1; i >= 0; i--)
    {
        while ((!st2.empty()) and (A[st2.top()] <= A[i]))
        {
            st2.pop();
        }
        if ((!st2.empty()))
            postFix[i] = st2.top();
        st2.push(i);
    }

    const long long int div = 1000000007;
    for (ll i = 0; i < A.size(); i++)
    {
        ans = max(ans, infixLarge[i] * postFix[i]);
    }

    return ans % div;
}

int maxSpecialProduct(vector<int> &A)
{
    int n = A.size();
    stack<pair<int, int>> st;

    long long int larr[n], rarr[n];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first <= A[i])
            st.pop();

        if (st.empty())
            larr[i] = 0;
        else
            larr[i] = st.top().second;
        st.push({A[i], i});
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first <= A[i])
            st.pop();

        if (st.empty())
            rarr[i] = 0;
        else
            rarr[i] = st.top().second;
        st.push({A[i], i});
    }

    long long int ans = -1;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, larr[i] * rarr[i]);
    }

    return ans % 1000000007;
}

// 84. Largest Rectangle in Histogram
int largestRectangleArea(vector<int> &heights)
{
    int val = heights[0], noTimes = 1;
    int ans = 0;
    int n = heights.size();

    stack<int> leftSmall, rightSmall;
    vector<int> leftSmallerVector(n, 0), rightSmallerVector(n, n - 1);

    for (size_t i = 0; i < n; i++)
    {
        while ((!leftSmall.empty()) and (heights[leftSmall.top()] >= heights[i]))
        {
            leftSmall.pop();
        }
        if (leftSmall.empty())
        {
            leftSmallerVector[i] = 0;
        }
        else
        {
            leftSmallerVector[i] = leftSmall.top() + 1;
        }
        leftSmall.push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while ((!rightSmall.empty()) and (heights[rightSmall.top()] >= heights[i]))
        {
            rightSmall.pop();
        }
        if (rightSmall.empty())
        {
            rightSmallerVector[i] = n - 1;
        }
        else
        {
            rightSmallerVector[i] = rightSmall.top() - 1;
        }
        rightSmall.push(i);
    }

    for (size_t i = 0; i < n; i++)
    {
        ans = max(ans, ((rightSmallerVector[i] - leftSmallerVector[i] + 1) * heights[i]));
    }

    return ans;
}

class MinStack
{
public:
    MinStack()
        : minEle{0}
    {
        while (!st.empty())
        {
            st.pop();
        }
    }

    void push(int val)
    {
        if (st.empty())
        {
            minEle = val;
            st.push(val);
        }
        else
        {
            if (val < minEle)
            {
                st.push((2 * (val)) - (minEle));
                minEle = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (minEle > st.top())
        {
            minEle = (2 * (minEle)) - (st.top());
        }
        st.pop();
    }

    int top()
    {
        if (minEle > st.top())
        {
            return minEle;
        }
        else
        {
            return st.top();
        }
    }

    int getMin()
    {
        return minEle;
    }

private:
    stack<int> st;
    int minEle;
};

// Sliding Window Maximum
//  [1, 3, -1, -3, 5, 3, 6, 7]
//
//   3 3 5 6
vector<int> slidingMaximum(const vector<int> &A, int B)
{
    // 18001084747
    deque<int> dq;
    vector<int> max;

    for (size_t i = 0; i < A.size(); i++)
    {
        if ((!dq.empty()) and (dq.size() > B))
        {
            dq.pop_front();
        }

        while ((!dq.empty()) and (dq.front() <= A[i]))
        {
            dq.pop_front();
        }

        if (i >= B - 1)
        {
            if (!dq.empty())
                max.push_back(dq.front());
            else
            {
                max.push_back(A[i]);
            }
        }
        dq.push_back(A[i]);
    }

    return max;
}

int main()
{
    string s = "((a+b))";
    vector<int> v = {2, 4};
    // string path = "/../";
    // string path = "/hello../world";
    // cout << solveNonRepeating1(s) << endl;
    cout << largestRectangleArea(v) << endl;
    return 0;
}