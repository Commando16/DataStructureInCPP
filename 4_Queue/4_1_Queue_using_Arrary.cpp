#include<iostream>

using namespace std;

class simpleQueue{
    int front = -1;
    int rear = -1;
    int *arr, n;
    public:
        simpleQueue(int max_length){
            n = max_length;
            arr = new int[n];
        }
        int getLength(){
            if (front == -1 && rear == -1)
            {
                return 0;
            }
            return rear-front+1;
        }
        void enqueue(int data){
            if(rear==n-1){
                cout<<"Queue overflow!"<<endl;
            }

            else{
                if(front==-1){
                    front = 0;
                }
                rear++;
                arr[rear] = data;
            }
        }
        void dequeue(){
            if(front==-1 || front > rear){
                front=-1;
                rear=-1; 
                cout<<"Queue underflow!"<<endl;
                return;
            }
            else{
                front++;                
            }
        }
        void display(){
           // cout<<front<<rear;
            if(front == -1 || front > rear){
                cout<<"Queue is empty!"<<endl;
                
            }
            else{
                for(int i=front; i<=rear; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
} q1(0);

int main(){
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(7);
    q1.enqueue(3);
    q1.enqueue(12);
    q1.enqueue(20);

    q1.display();

    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();


    return 0;
    
}