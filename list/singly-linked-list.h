#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node {
    Node *next;
    int data;
    
    explicit Node(int data) : Node(nullptr, data) {}
    Node(Node *next, int data) : next(next), data(data) {}
};

class SinglyLinkedList
{
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList();

    void insert(int data);
    void insertSorted(int data);
    Node* front();
    Node* find(int data);
};

#endif