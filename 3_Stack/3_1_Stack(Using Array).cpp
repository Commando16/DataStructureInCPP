#include<iostream>

using namespace std;



// Stack implementation using Array ( Static implementation / Static stack )

class Stack{
    int arr[10];
    int top = -1, size = 0;

    public:

    bool isEmpty(){
        if( top < 0 )
            return true;

        return false;
    }

    bool isFull(){
        if( top == 9)
            return true;

        return false;
    }

    void push(int data){
        if( isFull() )
        {
            cout<<"Stack overflow. No more push operation can be performed"<<endl;
        } 
        else{     
            top++;       
            arr[top] = data;
            size++;
        }
    }

    void pop(){        
        if( isEmpty() )
        { cout<<"Stack underflow. No more pop operation can be performed"<<endl; 
          //return 0;
        }
        else{            
            int a = arr[top];  
            top--;          
            size--;
            cout<<a<<" is popped out of the stack"<<endl;
            //return a;
        }
    }

    void peek(){
        if( isEmpty() )
        { cout<<"Stack underflow. No more pop operation can be performed"<<endl; }
        else{
            cout<<arr[top]<<" is the top most element value."<<endl;
        }
    }

    int stack_size(){
        return size;
    }

    void display(){
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


// Driver program
int main(){
    Stack s; 

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); 
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.peek();

    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    cout<<s.stack_size();

    

    return 0;
}