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
    Node *rare = NULL;
    int length = 0;

public:
    void enqueRare(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;
        newnode->nxt = NULL;

        if ((this->front == NULL) && (this->rare == NULL))
        {
            this->front = this->rare = newnode;
        }

        else
        {
            this->rare->nxt = newnode;
            this->rare = newnode;
        }

        this->length++;
    }

    void enqueFront(int data)
    {
        Node *newnode = new Node;
        newnode->data = data;

        if ((this->front == NULL) && (this->rare == NULL))
        {
            newnode->nxt = NULL;
            this->front = this->rare = newnode;
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

        while (tracer != this->rare)
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
    q.enqueRare(1);
    q.enqueRare(2);
    q.enqueRare(3);
    q.enqueRare(4);
    q.enqueRare(5);
    q.enqueRare(6);
    q.enqueRare(7);
    q.enqueFront(8);
    q.enqueRare(9);

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