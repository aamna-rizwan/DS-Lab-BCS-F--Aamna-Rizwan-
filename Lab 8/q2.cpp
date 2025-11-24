#include <iostream>
#include <string>
using namespace std;

struct Combatant{
    string name;
    int hp;
    int atk;
};

struct node{
    Combatant data;
    node *left;
    node *right;
};

node *newnode(Combatant c){
    node *t=new node;
    t->data=c;
    t->left=NULL;
    t->right=NULL;
    return t;
}

node *insertnode(node *root,Combatant c){
    if(root==NULL) return newnode(c);
    if(c.name < root->data.name){
        root->left=insertnode(root->left,c);
    }else{
        root->right=insertnode(root->right,c);
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
        else if(r->right==NULL){
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

void printTree(node *r){
    if(r==NULL) return;
    printTree(r->left);
    cout<<r->data.name<<"("<<r->data.hp<<") ";
    printTree(r->right);
}

node *getFrontline(node *root){
    if(root==NULL) return NULL;
    return minnode(root);
}

int main(){
    node *heroes=NULL;
    node *enemies=NULL;
    Combatant h1={"Hassan",30,6};
    Combatant h2={"Naheed",28,5};
    Combatant h3={"Ilsa",32,4};
    Combatant h4={"Shiza",26,7};
    Combatant h5={"Rimsha",34,3};
    heroes=insertnode(heroes,h1);
    insertnode(heroes,h2);
    insertnode(heroes,h3);
    insertnode(heroes,h4);
    insertnode(heroes,h5);
    Combatant e1={"Aamna",25,5};
    Combatant e2={"Laiba",20,4};
    Combatant e3={"Abeeha",35,3};
    Combatant e4={"Zunairah",22,6};
    Combatant e5={"Hammad",30,5};
    enemies=insertnode(enemies,e1);
    insertnode(enemies,e2);
    insertnode(enemies,e3);
    insertnode(enemies,e4);
    insertnode(enemies,e5);

    int round=1;

    while(heroes!=NULL && enemies!=NULL){
        cout<<"Round "<<round<< endl;

        cout<<"Heroes: ";
        printTree(heroes);
        cout<<"\nEnemies: ";
        printTree(enemies);
        cout<<endl;

        node *hfront=getFrontline(heroes);
        node *efront=getFrontline(enemies);

        cout<<"\nPlayer attacks first\n";
        int dmg=hfront->data.atk+1; 
        cout<<hfront->data.name<<" hits "<<efront->data.name<<" for "<<dmg<<"\n";
        efront->data.hp-=dmg;

        if(efront->data.hp<=0){
            cout<<efront->data.name<<" is defeated!\n";
            enemies=deletenode(enemies,efront->data.name);
            if(enemies==NULL){
                cout<<"\nPlayer wins the battle!\n";
                break;
            }
        }

        if(enemies!=NULL){
            efront=getFrontline(enemies);
            cout<<"\nEnemy counterattacks\n";
            int dmg2=efront->data.atk+1;
            cout<<efront->data.name<<" hits "<<hfront->data.name<<" for "<<dmg2<<"\n";
            hfront->data.hp-=dmg2;

            if(hfront->data.hp<=0){
                cout<<hfront->data.name<<" is defeated!\n";
                heroes=deletenode(heroes,hfront->data.name);
                if(heroes==NULL){
                    cout<<"\nEnemies win the battle!\n";
                    break;
                }
            }
        }

        round++;
    }

    return 0;
}
