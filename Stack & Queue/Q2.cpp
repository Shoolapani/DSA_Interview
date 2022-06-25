#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
public:
    Queue(int MAX_SIZE = 5)
        : currSize{-1}, front{0}, rear{0}, MAX_SIZE{5}
    {
        this->MAX_SIZE = MAX_SIZE;
        arr = new int[MAX_SIZE + 1];
    }

    ~Queue()
    {
        cout << "Deleting ALL Value" << endl;
        delete[] arr;
    }

    void push(T val);
    T pop(void);
    T top(void);
    void print(void);

private:
    int MAX_SIZE;
    int currSize;
    T *arr;
    int front, rear;
};

template <class T>
void Queue<T>::push(T val)
{
    if (currSize >= MAX_SIZE - 1)
    {
        cout << "Not Possible" << endl;
        return;
    }
    ++currSize;
    arr[rear % MAX_SIZE] = val;
    ++rear;
    return;
}

template <class T>
void Queue<T>::print()
{
    if (currSize <= 0)
    {
        cout << "Empty" << endl;
        return;
    }

    for (size_t i = front; i < rear; i++)
    {
        cout << arr[i % MAX_SIZE] << "\t";
    }
    cout << endl;
}

template <class T>
T Queue<T>::pop(void)
{
    if (currSize <= 0)
    {
        cout << "Empty" << endl;
        return INT_MAX;
    }
    --currSize;
    int val = arr[front % MAX_SIZE];
    ++front;
    return val;
}

template <class T>
T Queue<T>::top(void)
{
    if (front == rear)
    {
        cout << "Empty" << endl;
        return 0;
    }
    T val = arr[front % MAX_SIZE];
    return val;
}

int main()
{
    Queue<int> q;
    q.push(21);
    q.push(1);
    q.push(2);
    cout << q.top() << endl;
    q.push(2);
    q.push(2);
    cout << q.top() << endl;
    q.print();

    return 0;
}