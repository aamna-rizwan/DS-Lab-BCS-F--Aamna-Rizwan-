#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    int height;
};

int height(node *n){
    if(n==NULL) return 0;
    return n->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}

node* newnode(int d){
    node *n=new node;
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

node* rightRotate(node *y){
    node *x=y->left;
    node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

node* leftRotate(node *x){
    node *y=x->right;
    node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}

int getBalance(node *n){
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}

node* insert(node *root,int d){
    if(root==NULL) return newnode(d);
    if(d<root->data) root->left=insert(root->left,d);
    else if(d>root->data) root->right=insert(root->right,d);
    else return root;

    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);

    if(balance>1 && d<root->left->data) return rightRotate(root);
    if(balance<-1 && d>root->right->data) return leftRotate(root);
    if(balance>1 && d>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && d<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printBalance(node *root){
    if(root==NULL) return;
    printBalance(root->left);
    cout<<"Node "<<root->data<<" Balance Factor "<<getBalance(root)<<"\n";
    printBalance(root->right);
}

int main(){
    node *root=NULL;
    root=insert(root,10);
    insert(root,5);
    insert(root,15);
    insert(root,3);
    insert(root,7);
    root=insert(root,12);

    cout<<"Inorder traversal:\n";
    inorder(root);
    cout<<"\nBalance factors:" << endl;
    printBalance(root);
    cout<<"\nHeight of tree: "<<height(root)<<endl;
    return 0;
}
