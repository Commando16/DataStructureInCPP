#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *prev, *nxt;
};


class DLinkedList{
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

    void insertData( int indata, int pos=0 )
    {
        Node *newnode = new Node;
        newnode->data=indata;

        if( pos >= 0  &&  pos <= this->length)
        {
            if(pos==0 || this->start == NULL)
            {
                //cout<<"element added at start";
                newnode->prev = NULL;
                newnode->nxt = this->start;

                if(this->start!=NULL)
                {
                    this->start->prev = newnode;
                }
                this->start=newnode;
            }


            else if(pos<=this->length)
            {
                Node* tracer = this->start;

                for (int i = 1; i < pos; i++)
                {
                    tracer = tracer->nxt;
                }                

                newnode->nxt = tracer->nxt; //NULL
                newnode->prev = tracer;     // Tracer address
                //cout<<tracer->nxt->prev<<endl;
                if( tracer->nxt != NULL)
                {  
                    tracer->nxt->prev = newnode;
                }
                
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
                    start->nxt->prev = NULL;
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

                    if(tracer->nxt->nxt!=NULL)
                    {   tracer->nxt->nxt->prev = tracer;                     
                        tracer->nxt = tracer->nxt->nxt;
                    }
                    else{
                        tracer->nxt = NULL;
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

}o1;


int main()
{

    //cout<<"hello world"<<endl;
    o1.insertData(5);
    o1.showLinkedList();
    o1.insertData(1);
    o1.showLinkedList();
    //cout << o1.getLength() << endl;
    o1.insertData(8,1);
    // cout << o1.getLength() << endl;
    o1.showLinkedList();
    o1.insertData(7,2);
    //cout << o1.getLength() << endl;
    o1.showLinkedList();
    o1.insertData(10,4);
    // cout << o1.getLength() << endl;
    o1.showLinkedList();

    o1.deleteData(0);

    o1.showLinkedList();

    // o1.showLinkedList();

     //o1.deleteData(4);
    // cout << o1.getLength() << endl;

     //o1.showLinkedList();
    // o1.deleteData();
    //cout<<"end world"<<endl;



    return 0;
}
