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
    void enque(int data)
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

    int dequeueFront()
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

    int dequeueRear()
    {
        if (this->front == NULL)
        {
            cout << "The Queue is empty. Queue undeflown." << endl;
            return -999;
        }
        else
        {
            Node *del_ptr;
            int data;

            Node *tracer = this->front;

            while ( tracer->nxt != this->rear )
            {
                tracer = tracer->nxt;
            }

            data =  this->rear->data;
            del_ptr = this->rear;

            tracer->nxt = NULL;
            this->rear = tracer;

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

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.enque(6);
    q.enque(7);
    q.enque(8);

    q.displayQueue();

    cout << q.dequeueFront() << " dequeued from front" << endl;
    cout << q.dequeueFront() << " dequeued from front" << endl;
    cout << q.dequeueFront() << " dequeued from front" << endl;

    cout << q.dequeueRear() << " dequeued from rear" << endl;
    cout << q.dequeueRear() << " dequeued from rear" << endl;

    q.displayQueue();   

    cout << "Length if the queue is- " << q.queueLength() << endl;

    return 0;
}