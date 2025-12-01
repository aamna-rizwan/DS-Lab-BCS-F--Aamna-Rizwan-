#include <iostream>
using namespace std;
const int MAX = 5;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node *adjList[MAX+1]; //so we can directly access adjList[5]
int adjMatrix[MAX+1][MAX +1];

//insertion
void addEdgeList(int u,int v){
    Node*temp= new Node(v);
    temp->next=adjList[u];
    adjList[u]=temp;
}
void addEdgeMatrix(int u,int v){
    adjMatrix[u][v]=1;
    adjMatrix[v][u]=1;
}

//DFS
bool visitedDFS[MAX+1];
void DFS(int node){
    visitedDFS[node]=true;
    cout << node << " ";
    
    Node *temp=adjList[node];
    while(temp){
        if(!visitedDFS[temp->data]){
            DFS(temp->data);
        }
        temp=temp->next;
    }
}

//BFS 
bool visitedBFS[MAX+1];
    int queueArr[100];
    int front=0;
    int rear=0;
void enqueue(int x){
    queueArr[rear]=x;
    rear++;
}
int dequeue(){
    int x= queueArr[front];
    front++;
    return x;
}
bool isEmpty(){
    return (front==rear || front > rear);
}

void BFS(int start){
    for (int i = 1; i <= MAX; i++){
        visitedBFS[i] = false;
     }
    enqueue(start);
    visitedBFS[start]=true;
    while(!isEmpty()){
        int node=dequeue();
        cout << node << " ";
        Node *temp=adjList[node];
        while(temp!=NULL){
            if(!visitedBFS[temp->data]){
                enqueue(temp->data);
                visitedBFS[temp->data]=true;
            }
            temp=temp->next;
        }
    }
}


int main() {
   
    for (int i = 1; i <= MAX; i++){
        adjList[i] = NULL;
    }
    
    for (int i = 1; i <= MAX; i++){
        visitedDFS[i] = false;
    }
    
    int edges[][2] = {{1,4},{4,2},{2,5},{3,5},{4,5}};

    int totalEdges = 5;

    for (int i = 0;i<totalEdges;i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdgeList(u, v);
        addEdgeList(v, u);
        addEdgeMatrix(u, v);
    }
    cout << "Adjacency List:\n";
    for (int i = 1; i <= MAX; i++) {
        cout << i << " -> ";
        Node* temp = adjList[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nDFS Traversal (start from 1): ";
    DFS(1);
    cout << "\nBFS Traversal (start from 1): ";
    BFS(1);
    cout << endl;
    return 0;
}
