#include "singly-linked-list.h"

SinglyLinkedList::~SinglyLinkedList()
{
    while (head != nullptr)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void SinglyLinkedList::insert(int value)
{
    head = new Node(head, value);
}

Node* SinglyLinkedList::front()
{
    return head;
}