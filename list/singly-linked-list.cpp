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

void SinglyLinkedList::insert(int data)
{
    head = new Node(head, data);
}

Node* SinglyLinkedList::front()
{
    return head;
}

void SinglyLinkedList::insertSorted(int data)
{
    if (head == nullptr || data <= head->data)
    {
        head = new Node(head, data);
        return;
    }

    Node* current = head;
    while (current->next != nullptr && data > current->next->data)
    {
        current = current->next;
    }

    current->next = new Node(current->next, data);
}

Node* SinglyLinkedList::find(int data)
{
    Node* current = head;
    while (current != nullptr && current->data != data)
    {
        current = current->next;
    }
    return current;
}