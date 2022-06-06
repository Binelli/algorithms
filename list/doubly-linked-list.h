#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DLLNode
{
    DLLNode* prev;
    DLLNode* next;
    int data;

    explicit DLLNode(int data) : DLLNode(this, this, data) {}
    DLLNode(DLLNode* prev, DLLNode *next, int data) : prev(prev), next(next), data(data) {}
};

class DoublyLinkedList
{
private:
    DLLNode *head;
public:
    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList();

    DLLNode* insert(int data);
    DLLNode* front();
    DLLNode* find(int value);
};

#endif