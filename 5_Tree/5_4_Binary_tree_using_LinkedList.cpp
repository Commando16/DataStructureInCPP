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

    Node* generate(){
        int data = 0;
        Node* Root = new Node;

        cout<< "Enter some interger data- ";
        cin>> data;


        Root->data = data;
        Root->left = NULL;
        Root->right = NULL;

        this->size++;


        // creating left node if the decision is Y
        char decision = 'N';
        cout<< "Do you want to insert a child node to the left of "<<Root->data<<" Y/N- ";
        cin>> decision;

        if( decision == 'Y' or decision == 'y'){
            Root->left = generate();
        } 
        

        // creating right node if the decision is Y
        decision = 'N';
        cout<< "Do you want to insert a child node to the right of "<<Root->data<<" Y/N- ";
        cin>> decision;

        if( decision == 'Y' or decision == 'y'){
            Root->right = generate();
        }
        

        return Root;
    }

    public:

    void create(){
        root = generate();
    }

    Node* getRoot(){
        return this->root;
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
    t1.create();
    t1.inorderTraversal(t1.getRoot());
    cout<<endl;
    return 0;
}