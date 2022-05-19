#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node {
    Node *next;
    int data;
    
    explicit Node(int data) : Node(nullptr, data) {}
    Node(Node *head, int data) : next(head), data(data) {}
};

class SinglyLinkedList
{
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList();

    void insert(int data);
    Node* front();
};

#endif