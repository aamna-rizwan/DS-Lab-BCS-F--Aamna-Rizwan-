/* Since the tree is currently 10 -> 20 -> 30 -> 40 -> 50 (all right child) so
15 will be inserted as the left child of 20
Balancing is needed as the tree is right - heavy*/
/* the new height of the AVL tree will be same as before : 5 */

#include <iostream>
using namespace std;

struct Student{
    int roll;
    string name;
};

struct node{
    Student data;
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

node* newnode(Student s){
    node *n=new node;
    n->data=s;
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

node* insert(node *root,Student s){
    if(root==NULL) return newnode(s);
    if(s.roll<root->data.roll) root->left=insert(root->left,s);
    else if(s.roll>root->data.roll) root->right=insert(root->right,s);
    else return root;

    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);

    if(balance>1 && s.roll<root->left->data.roll) return rightRotate(root);
    if(balance<-1 && s.roll>root->right->data.roll) return leftRotate(root);
    if(balance>1 && s.roll>root->left->data.roll){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && s.roll<root->right->data.roll){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data.roll<<"("<<root->data.name<<") ";
    inorder(root->right);
}

int main(){
    node *root=NULL;
    root=insert(root,{10,"S1"});
    insert(root,{20,"S2"});
    insert(root,{30,"S3"});
    insert(root,{40,"S4"});
    insert(root,{50,"S5"});

    root=insert(root,{15,"newStudent"});
    cout<<"traversal of balanced AVL tree: \n";
    inorder(root);
}


