#include <conio.h>
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *nxt;
};

class SLinkedList
{
    Node *start = NULL;
    int length = 0;

public:
    int getLength()
    {
        return this->length;
    }

    void showLinkedList()
    { //cout<<"show linked list"<<endl;

        if (this->length <= 0)
        {
            cout << "The list is empty."<<endl;
        }
        else
        {
            Node *tracer = this->start;
            while (tracer != NULL)
            {
                cout << tracer->data << " ";
                tracer = tracer->nxt;
            }
            cout << endl;
        }
    }

    void insertData(int indata, int pos = 0)
    { //cout<<"insert"<<endl;
        Node *newnode = new Node;
        newnode->data = indata;

        if (pos >= 0 && pos <= this->length)
        {
            if (this->start == NULL or pos == 0) //insert at start
            {
                newnode->nxt = this->start;
                this->start = newnode;
            }

            // else if (pos == this->length) //insert at end
            // {
            //     Node *tracer = this->start;

            //     while (tracer->nxt != NULL)
            //     {
            //         tracer = tracer->nxt;
            //     }

            //     newnode->nxt = NULL;
            //     tracer->nxt = newnode;
            // }

            else if (pos <= this->length)
            { //cout<<"else condition"<<endl;
                Node *tracer = this->start;

                for (int i = 1; i < pos; i++)
                {
                    tracer = tracer->nxt;
                }
                newnode->nxt = tracer->nxt;
                tracer->nxt = newnode;
            }
        }
        else
        {
            cout << "The position you entered is wrong! Please enter valid position." << endl;
        }

        this->length++;
    }

    void deleteData(int pos = 0)
    {
        Node *dlt_ptr = NULL;
        if (this->length == 0)
        {
            cout << "There is no data to be deleted!"<<endl;
        }
        else
        {

            if (pos >= 0 && pos < this->length)
            {
                if (pos == 0)
                {
                    dlt_ptr = start;
                    start = start->nxt;
                }
                else
                {
                    Node *tracer = this->start;

                    for (int i = 1; i < pos; i++)
                    {
                        tracer = tracer->nxt;
                    }
                    dlt_ptr = tracer->nxt;
                    tracer->nxt = tracer->nxt->nxt;
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
}o1;

int main()
{

    //cout<<"hello world"<<endl;
    o1.insertData(5);
    o1.showLinkedList();
    o1.insertData(1);
    //cout << o1.getLength() << endl;
    o1.insertData(8,1);
    // cout << o1.getLength() << endl;
    o1.showLinkedList();
    o1.insertData(7,2);
    // cout << o1.getLength() << endl;
    o1.showLinkedList();
    o1.insertData(10,4);
    // cout << o1.getLength() << endl;
    o1.showLinkedList();
    // o1.showLinkedList();

     //o1.deleteData(4);
    // cout << o1.getLength() << endl;

     //o1.showLinkedList();
    // o1.deleteData();
    //cout<<"end world"<<endl;



    return 0;
}
