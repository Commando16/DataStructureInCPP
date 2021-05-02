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
        void enqueue_front(int data){
            if(rear>n-2){
                cout<<"Queue overflow!"<<endl;
            }

            else{
                
                if(front==-1){
                    // cout<<"first if chala";
                    front = 0;
                    rear++;
                    arr[rear] = data;
                    return;
                }             
                else if(front>0){
                    front--;
                    arr[front]=data;
                    return;
                }
                else{
                    // cout<<"front at position-"<<front<<endl;
                    // cout<<"rear at position-"<<rear<<endl; 
                    for(int i=rear; i>=front; i-- ){
                        arr[i+1] = arr[i];
                    }
                    arr[front] = data;  
                    rear++;                  
                }
                // else{
                //     cout<<"There is no space in front end."<<endl;
                // }
            }
        }
        void enqueue_rare(int data){
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
} q1(10);

int main(){
    q1.enqueue_front(8);
    q1.display();
    q1.enqueue_front(23);
    q1.display();
    q1.enqueue_front(9);
    q1.display();
    q1.enqueue_rare(57);
    q1.display();
    q1.dequeue(); 
    q1.display();
    q1.dequeue(); 
    q1.display();
    // q1.dequeue(); 
    // q1.display();
    // q1.dequeue(); 
    // q1.display();
    // q1.dequeue(); 
    // q1.display();
    q1.enqueue_front(24);
    q1.display();
    q1.enqueue_front(12);
    q1.display();
    q1.enqueue_front(3);
    q1.display();
    cout<<q1.getLength()<<endl;

    return 0;
}