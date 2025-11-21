#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot;
    *newHead = nullptr;
    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if ((*newHead) == nullptr) {
                *newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        } else {
            if (prev)
                prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if ((*newHead) == nullptr)
        *newHead = pivot;

    *newEnd = tail;
    return pivot;
}


Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

  
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;
        newHead = quickSortRecur(newHead, temp);
        Node* last = newHead;
        while (last->next != nullptr)
            last = last->next;
        last->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}


void quickSort(Node** headRef) {
    if (!(*headRef) || !(*headRef)->next)
        return;

    Node* end = *headRef;
    while (end->next != nullptr)
        end = end->next;

    *headRef = quickSortRecur(*headRef, end);
}


void push(Node** headRef, int data) {
    Node* newNode = new Node(data);
    newNode->next = *headRef;
    *headRef = newNode;
}


int main() {
    Node* head = nullptr;
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    push(&head, 9);
}
