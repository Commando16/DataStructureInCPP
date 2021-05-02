#include <iostream>

using namespace std;

class simpleQueue
{
    int front = -1;
    int rear = -1;
    int *arr, n;

public:
    simpleQueue(int max_length)
    {
        n = max_length;
        arr = new int[n];
    }
    int getLength()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        return rear - front + 1;
    }
    void enqueue(int data)
    {
        if ((front == 0 && rear == n - 1) || front == rear + 1)
        {
            cout << "Queue overflow!" << endl;
        }

        else
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                if (rear == n - 1)
                {
                    rear = 0;
                }
                else
                {
                    rear++;
                }
            }
            arr[rear] = data;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue underflow!" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }
    void display()
    {
        // cout<<front<<rear;
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
        }

        else
        {
            if (front <= rear)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            else
            {
                for (int i = front; i <= n - 1; i++)
                {
                    cout << arr[i] << " ";
                }

                front = 0;
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }
    }
} q1(10);

int main()
{
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(7);
    q1.enqueue(3);
    q1.enqueue(12);
    q1.enqueue(20);

    q1.display();

    q1.dequeue();

    q1.display();
    cout << q1.getLength();

    return 0;
}