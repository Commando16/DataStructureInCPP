#include <iostream>

using namespace std;

class QueueLL
{

    struct Node
    {
        int data;
        Node *nxt;
    };

    Node *front = NULL;
    Node *rear = NULL;
    int length = 0;

public:
    void enqueRear(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;
        newnode->nxt = NULL;

        if ((this->front == NULL) && (this->rear == NULL))
        {
            this->front = this->rear = newnode;
        }

        else
        {
            this->rear->nxt = newnode;
            this->rear = newnode;
        }

        this->length++;
    }

    void enqueFront(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;

        if ((this->front == NULL) && (this->rear == NULL))
        {
            newnode->nxt = NULL;
            this->front = this->rear = newnode;
        }

        else
        {
            newnode->nxt = this->front;
            this->front = newnode;
        }

        this->length++;
    }

    int dequeue()
    {
        if (this->front == NULL)
        {
            cout << "The Queue is empty. Queue undeflown." << endl;
            return -999;
        }
        else
        {
            Node *del_ptr = this->front;

            int data = this->front->data;
            this->front = this->front->nxt;

            this->length--;
            delete del_ptr;
            return data;
        }
    }

    int queueLength()
    {
        return this->length;
    }

    void displayQueue()
    {
        Node *tracer = this->front;

        while (tracer != this->rear)
        {
            cout << tracer->data << " ";
            tracer = tracer->nxt;
        }

        cout << tracer->data << endl;
    }
};

int main()
{

    QueueLL q;

    cout << "Length if the queue is- " << q.queueLength() << endl;

    q.enqueFront(0);
    q.enqueRear(1);
    q.enqueRear(2);
    q.enqueRear(3);
    q.enqueRear(4);
    q.enqueRear(5);
    q.enqueRear(6);
    q.enqueRear(7);
    q.enqueFront(8);
    q.enqueRear(9);

    q.displayQueue();

    cout << q.dequeue() << " dequeued" << endl;
    cout << q.dequeue() << " dequeued" << endl;
    cout << q.dequeue() << " dequeued" << endl;
    cout << q.dequeue() << " dequeued" << endl;
    cout << q.dequeue() << " dequeued" << endl;
    cout << q.dequeue() << " dequeued" << endl;

    q.displayQueue();

    cout << "Length if the queue is- " << q.queueLength() << endl;

    return 0;
}