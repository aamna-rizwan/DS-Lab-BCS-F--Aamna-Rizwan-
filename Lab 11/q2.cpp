#include <iostream>
#include <string>
using namespace std;
const int TABLE_SIZE = 100;

class Node{
    public:
    int key;
    string value;
    Node *next;
    Node(int k, const string &v){
        key=k;
        value=v;
        next=nullptr;
    }
};
class Hash{
    public:
    Node *table[TABLE_SIZE];
    
    int hashFunction(int key,string v){
    int sum = 0
    for(int i=0;i<v.length();i++){
        sum = sum +v[i];
        }
        return sum%100;
    }
    
    void add_record(string msg){
        int index = hashFunction (key,msg);
        Node *newNode = new Node (key, msg);
        if(table[index] == nullptr){
            table[index]=newNode;
        }else{
            if(temp->key==key){
            Node *temp=table[index];
            Node *store = head;
            head=temp;
            temp->next=store;
            delete newNode;
            return;
        }
    }
    
    string word_search(string msg,int key){
        int index = hashFunction(key);
        Node *temp= table[index];
        while(temp!=nullptr){
            if(temp->key==key){
                return temp->value;
            }
            temp=temp->next;
        }
        return "Error! Not found\n";
    }
    
    void print_dictionary() {
    for (int i=0;i<TABLE_SIZE;i++) {
        cout << "index " << i << ": ";
        Node* temp=hashTable[i];
        if (!temp) {
            cout << "no value" << endl;
        }
        while (temp != nullptr) {
            cout << "(" << temp->key << ", " << temp->value << ") ";
            temp=temp->next;
        }
        cout << endl;
    }
}
    void delete (int key){
        int index=hashFunction (key);
        Node *temp=table[index];
        Node *prev=nullptr;
        while (temp!=nullptr && temp->key!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp=nullptr){
            cout << "Key" << key << "not found\n" << endl;
            return;
        }
        if(prev=nullptr){
            table[index]=temp->next;
        }else
        prev->next = temp->next;
        delete temp;
        cout << "Key " << key << "deleted successfully " << endl;
    }
};

int main() {
   return 0;
}
