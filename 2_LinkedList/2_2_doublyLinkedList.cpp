#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev, *nxt;
};

class DLinkedList
{
    Node *start = NULL;
    int length = 0;

public:
    int getLength()
    {
        return this->length;
    }

    void showLinkedList()
    {

        if (this->length <= 0)
        {
            cout << "The list is empty." << endl;
        }
        else
        {
            Node *tracer = this->start;
            for (int i = 0; i < this->length; i++)
            {
                cout << tracer->data << " ";
                tracer = tracer->nxt;
            }
            cout << endl;
        }
    }

    void insertData(int indata, int pos = 0)
    {
        Node *newnode = new Node;
        newnode->data = indata;

        if (pos >= 0 && pos <= this->length)
        {
            if (this->start == NULL)
            {

                this->start = newnode;
                newnode->prev = this->start;
                newnode->nxt = this->start;
            }

            else if (pos == 0)
            {

                Node *tracer = this->start;

                for (int i = 1; i < pos; i++)
                {
                    tracer = tracer->nxt;
                }

                newnode->prev = tracer->nxt;
                newnode->nxt = this->start;

                this->start->prev = newnode;
                this->start = newnode;
            }

            else if (pos <= this->length)
            {
                Node *tracer = this->start;

                for (int i = 1; i < pos; i++)
                {
                    tracer = tracer->nxt;
                }

                newnode->nxt = tracer->nxt;
                newnode->prev = tracer;

                if (tracer->nxt != this->start)
                {
                    tracer->nxt->prev = newnode;
                }

                tracer->nxt = newnode;
            }

            this->length++;
        }
        else
        {
            cout << "The position you entered is wrong! Please enter valid position." << endl;
        }
    }

    void deleteData(int pos = 0)
    {
        Node *dlt_ptr = NULL;
        if (this->length == 0)
        {
            cout << "There is no data to be deleted!" << endl;
        }
        else
        {

            if (pos >= 0 && pos < this->length)
            {

                if (start->nxt == start)
                {
                    dlt_ptr = start;
                    start = NULL;
                }

                else if (pos == 0)
                {
                    dlt_ptr = start;

                    Node *tracer = this->start;
                    for (int i = 1; i < length; i++)
                    {
                        tracer = tracer->nxt;
                    }

                    start->nxt->prev = tracer->nxt;
                    this->start = start->nxt;
                    tracer->nxt = start;
                }
                else
                {
                    Node *tracer = this->start;

                    for (int i = 1; i < pos; i++)
                    {
                        tracer = tracer->nxt;
                    }

                    dlt_ptr = tracer->nxt;

                    if (tracer->nxt->nxt != this->start)
                    {
                        tracer->nxt->nxt->prev = tracer;
                        tracer->nxt = tracer->nxt->nxt;
                    }
                    else
                    {
                        tracer->nxt = this->start;
                    }
                }
                delete dlt_ptr;
                this->length--;
            }
            else
            {
                cout << "Invaild Position!" << endl;
            }
        }
    }

} o1;

int main()
{

    o1.insertData(5);
    o1.showLinkedList();
    o1.insertData(1);
    o1.showLinkedList();
    o1.insertData(8, 1);
    o1.showLinkedList();
    o1.insertData(7, -1);
    o1.showLinkedList();
    o1.deleteData(-1);

    o1.showLinkedList();

    return 0;
}
