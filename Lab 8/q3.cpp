#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int roll;
    int score;
};

struct node{
    Student data;
    node *left;
    node *right;
};

node *newnode(Student s){
    node *t=new node;
    t->data=s;
    t->left=NULL;
    t->right=NULL;
    return t;
}

node *insertnode(node *root,Student s){
    if(root==NULL) return newnode(s);
    if(s.name < root->data.name){
        root->left=insertnode(root->left,s);
    }else{
        root->right=insertnode(root->right,s);
    }
    return root;
}

node *minnode(node *r){
    while(r->left!=NULL){
        r=r->left;
    }
    return r;
}

node *deletenode(node *r,string name){
    if(r==NULL) return r;
    if(name < r->data.name){
        r->left=deletenode(r->left,name);
    }else if(name > r->data.name){
        r->right=deletenode(r->right,name);
    }else{
        if(r->left==NULL){
            node *t=r->right;
            delete r;
            return t;
        }
        if(r->right==NULL){
            node *t=r->left;
            delete r;
            return t;
        }
        node *t=minnode(r->right);
        r->data=t->data;
        r->right=deletenode(r->right,t->data.name);
    }
    return r;
}

node *searchnode(node *r,string n){
    if(r==NULL) return NULL;
    if(n==r->data.name) return r;
    if(n < r->data.name) return searchnode(r->left,n);
    return searchnode(r->right,n);
}

void delscore(node *&root){
    if(root==NULL) return;
    delscore(root->left);
    delscore(root->right);
    if(root->data.score < 10){
        root=deletenode(root,root->data.name);
    }
}

Student getmaxscore(node *r){
    Student maxs=r->data;
    if(r->left!=NULL){
        Student t=getmaxscore(r->left);
        if(t.score > maxs.score) maxs=t;
    }
    if(r->right!=NULL){
        Student t=getmaxscore(r->right);
        if(t.score > maxs.score) maxs=t;
    }
    return maxs;
}

void inorder(node *r){
    if(r==NULL) return;
    inorder(r->left);
    cout<<r->data.name<<" "<<r->data.roll<<" "<<r->data.score<<"\n";
    inorder(r->right);
}

int main(){
    Student arr[10]={
        {"Ali",1,12},
        {"Zain",2,5},
        {"Hadi",3,18},
        {"Musa",4,7},
        {"Sara",5,20},
        {"Alina",6,9},
        {"Kiran",7,11},
        {"Fahad",8,30},
        {"Babar",9,15},
        {"Rida",10,4}
    };

    node *root=NULL;

    insertnode(root,arr[0]);
    insertnode(root,arr[3]);
    insertnode(root,arr[5]);
    insertnode(root,arr[1]);
    insertnode(root,arr[7]);
    insertnode(root,arr[2]);
    insertnode(root,arr[6]);

    cout<<"Stored Students:\n";
    inorder(root);

    cout<<"\nSearch student Hadi:\n";
    node *s=searchnode(root,"Hadi");
    if(s!=NULL) cout<<s->data.name<<" "<<s->data.roll<<" "<<s->data.score<<"\n";
    else cout<<"not found\n";

    cout<<"\nDeleting students with score < 10\n";
    delscore(root);

    cout<<"After deletion:\n";
    inorder(root);

    cout<<"\nStudent with max score:\n";
    Student mx=getmaxscore(root);
    cout<<mx.name<<" "<<mx.roll<<" "<<mx.score<<"\n";

    return 0;
}
