#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    Queue(int MAX_SIZE = 100)
    {
        // Default MAX_SIZE
        this->MAX_SIZE = MAX_SIZE;
        arr = new int[MAX_SIZE];
        memset(arr, -1, MAX_SIZE);

        front = rear = 0;
        currentSize = 0;
    }

    void push(int newNumber)
    {
        if (currentSize > MAX_SIZE)
        {
            cout << "Not" << endl;
            return;
        }
        ++currentSize;
        arr[rear % MAX_SIZE] = newNumber;
        ++rear;
    }

    int pop()
    {
        if (currentSize == 0)
        {
            cout << "Empty" << endl;
            front = rear = 0;
            exit(1);
        }
        --currentSize;
        int l_temp = arr[front % MAX_SIZE];
        --front;
        return l_temp;
    }

    int top()
    {
        if (currentSize == 0)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[front % MAX_SIZE];
    }

    int size()
    {
        return currentSize;
    }

    ~Queue()
    {
        delete[] arr;
    }

private:
    int MAX_SIZE;
    int *arr;
    int front;
    int rear;
    int currentSize;
};

int main()
{
    Queue q;
    for (size_t i = 0; i < 10; i++)
    {
        q.push(i);
    }
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;
    return 0;
}