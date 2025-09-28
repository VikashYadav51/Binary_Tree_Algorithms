#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int element){
        this->data = element;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* build_tree(){
    int data;
    cout <<"Enter the data "<< endl;
    cin>> data;

    Node* root = new Node(data);

    if(data == -1){
        return nullptr;
    }

    cout <<"Enter the data left side of "<< data << endl;
    root->left = build_tree();

    cout <<"Enter the data right side of "<< data << endl;
    root->right = build_tree();

    return root;
}


void print_data(Node* root){
    if(root == nullptr){
        return ;
    }

    queue<Node* > q1;
    q1.push(root);

    while(!q1.empty()){
        int size = q1.size();
        int i = 0;
        while(i < size){
            Node* temp = q1.front();
            q1.pop();

            cout << temp->data <<"  ";

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
            i++;
        }

        cout << endl;
    }

}


void Print_Inorder(Node* root){
    if(root == nullptr){
        return ;
    }

    Print_Inorder(root->left);
    cout<< root->data <<"  ";
    Print_Inorder(root->right);

}

void Print_Preorder(Node* root){
    if(root == nullptr){
        return ;
    }

    cout<< root->data <<"  ";
    Print_Preorder(root->left);
    Print_Preorder(root->right);

}

void Print_Postorder(Node* root){
    if(root == nullptr){
        return ;
    }

    Print_Postorder(root->left);
    Print_Postorder(root->right);
    cout<< root->data <<"  ";

}


int main(){

    Node* root = build_tree();

    cout <<"Print the data in LOT way "<< endl;
    print_data(root);
    cout << endl << endl;

    cout << "Print the data in Inorder way "<< endl;
    Print_Preorder(root);
    cout << endl << endl;

    cout << "Print the data in Preorder way "<< endl;
    Print_Inorder(root);
    cout << endl << endl;

    cout << "Print the data in Postorder way "<< endl;
    Print_Postorder(root);
    cout << endl << endl;

    
    return 0;
}