#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *newnode(int x){
    node *t=new node;
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    return t;
}

node *insertnode(node *root,int x){
    if(root==NULL) return newnode(x);
    if(x<root->data){
        root->left=insertnode(root->left,x);
    }else{
        root->right=insertnode(root->right,x);
    }
    return root;
}

node *minnode(node *r){
    while(r->left!=NULL){
        r=r->left;
    }
    return r;
}

node *deletenode(node *r,int x){
    if(r==NULL) return r;

    if(x<r->data){
        r->left=deletenode(r->left,x);
    }else if(x>r->data){
        r->right=deletenode(r->right,x);
    }else{
        if(r->left==NULL){
            node *t=r->right;
            delete r;
            return t;
        }
        else if(r->right==NULL){
            node *t=r->left;
            delete r;
            return t;
        }
        node *t=minnode(r->right);
        r->data=t->data;
        r->right=deletenode(r->right,t->data);
    }
    return r;
}

bool searchnode(node *r,int x){
    if(r==NULL) return false;
    if(r->data==x) return true;
    if(x<r->data) return searchnode(r->left,x);
    return searchnode(r->right,x);
}

void inorder(node *r){
    if(r==NULL) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void preorder(node *r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void postorder(node *r){
    if(r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main(){
    node *root=NULL;
    root=insertnode(root,5);
    insertnode(root,3);
    insertnode(root,7);
    insertnode(root,2);
    insertnode(root,4);
    insertnode(root,6);
    cout<<"inorder:\n";
    inorder(root);
    cout<<"\npreorder:\n";
    preorder(root);
    cout<<"\npostorder:\n";
    postorder(root);
    cout<<searchnode(root,4)<<"\n";
    root=deletenode(root,7);
    cout<<"after delete:\n";
    inorder(root);
}
