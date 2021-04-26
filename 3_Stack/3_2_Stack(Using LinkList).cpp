#include <iostream>

using namespace std;

// Stack implementation using Array ( Static implementation / Static stack )

class LinkedList
{
    struct node
    {
        int data;
        node *nxt;
    };

    node *start = NULL;
    node *top = NULL;

public:
    void insertElement(int data)
    {
        node *newnode = new node;

        newnode->data = data;
        newnode->nxt = start;

        start = newnode;  
    }

    int deleteElement()
    {
        int x;
        node *delptr = start;

        x = start->data;
        start = start->nxt;

        delete delptr;
        return x;
    }

    void displayList()
    {
        node *tracer = start;

        while (tracer != NULL)
        {
            cout << tracer->data << " ";
            tracer = tracer->nxt;
        }

    }

    int startData()
    {
        return start->data;
    }
};

class Stack
{
    LinkedList ll;
    int top = -1, size = 0;

public:
    bool isEmpty()
    {   cout<<"top is at-"<<top<<endl;
        if (top < 0)
            return true;

        return false;
    }

    void push(int data)
    {
        top++;
        ll.insertElement(data);
        size++;
    }

    void pop()
    {
        
        if (isEmpty())
        {
            cout << "Stack underflow. No more pop operation can be performed" << endl;
            return 0;
        }
        else            
        {   top--;
            int a = ll.deleteElement();
            size--;
            return a;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. No more pop operation can be performed" << endl;
        }
        else
        {
            cout << ll.startData() << " is the top most element value." << endl;
        }
    }

    int stack_size()
    {
        return size;
    }

    void display()
    {
        ll.displayList();
        cout << endl;
    }
};

// Driver program
int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(33);
    s.display();    
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
