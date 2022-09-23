#include<bits/stdc++.h>
using namespace std;

template <typename N>class NodeQueue
{
public:
    N value;
    NodeQueue* next;

    NodeQueue(N val)
    {
        value = val;
        next = NULL;
    }
};

template<typename Q> class Queue
{
    NodeQueue<Q>* front;
    NodeQueue<Q>* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    //enqueue --> push
    void push(Q val)
    {
        NodeQueue<Q>* newNodeQueue = new NodeQueue<Q>(val);

        if(front == NULL)
        {
            front = newNodeQueue;
            rear = newNodeQueue;
            return;
        }
        rear->next = newNodeQueue;
        rear = rear->next;
    }

    //deque --> pop
    Q pop()
    {
        Q chk;
        if(rear == NULL)
        {
            cout<<"Queue Underflow | There is no element in the QUEUE"<<endl;
            return chk;;
        }
        NodeQueue<Q>* delNodeQueue;
        delNodeQueue = front;
        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        chk = delNodeQueue->value;
        delete delNodeQueue;
        return chk;
    }

    //peek --> front()  back()
    Q Front()
    {
       Q chk;
       chk = front->value;
       return chk;
    }

    Q Back()
    {
        Q chk;
        chk = rear->value;
        return chk;
    }

    //empty --> empty()
    bool empty()
    {
        if(front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
