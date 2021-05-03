#include<iostream>

using namespace std;

class Tree{

    struct Node{
        int data;
        Node* left;
        Node* right;
    };

    int size = 0;

    Node* root = NULL;

    public:


    Node* getRoot(){
        return this->root;
    }

    void insert(int data){

        Node* newnode = new Node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;

        if( this->root == NULL )
        {
            this->root = newnode;
        }
        else{
            Node* tracer = this->root; 

            while( true ){
                if( data > tracer->data ){
                    if( tracer->right == NULL ){
                        tracer->right = newnode;
                        break;
                    }
                    else{
                        tracer = tracer->right;
                    }
                }
                else{
                    if( tracer->left == NULL ){
                        tracer->left = newnode;
                        break;
                    }
                    else{
                        tracer = tracer->left;
                    }
                }

            }


        }
    }





    void preorderTraversal( Node* Root ){
        if(Root == NULL){
            return;
        }

        cout<< Root->data<< " ";
        preorderTraversal(Root->left);
        preorderTraversal(Root->right);

        return;
    }

    void inorderTraversal( Node* Root ){
        if(Root == NULL){
            return;
        }

        inorderTraversal(Root->left);
        cout<< Root->data<< " ";
        inorderTraversal(Root->right);

        return;
    }

    void postorderTraversal( Node* Root ){
        if(Root == NULL){
            return;
        }

        postorderTraversal(Root->left);
        postorderTraversal(Root->right);
        cout<< Root->data<< " ";

        return;
    }
    
};


//deriver code
int main(){
    Tree t1;
    t1.insert( 10 );
    t1.insert( 8 );
    t1.insert( 7 );
    t1.insert( 12 );
    t1.insert( 9 );
    t1.insert( 11 );
    t1.insert( 6 );
    t1.insert( 5 );
    t1.insert( 4 );
    t1.insert( 6 );
    t1.insert( 6 );

    t1.inorderTraversal(t1.getRoot());


    return 0;
}