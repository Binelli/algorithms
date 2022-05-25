#include "singly-linked-list.h"

SinglyLinkedList::~SinglyLinkedList()
{
    if (head != nullptr)
    {
        Node* next = head->next;
        while (next != nullptr && next != head)
        {
            Node* tmp = next;
            next = next->next;
            delete tmp;
        }
        delete head;
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

void SinglyLinkedList::remove(Node* target)
{
    if (target == nullptr || head == nullptr)
    {
        return;
    }
    
    if (target == head)
    {
        head = head->next;
        delete target;
        return;
    }

    Node* prev = head;
    while (prev->next != nullptr && prev->next != target)
    {
        prev = prev->next;
    }

    if (prev->next == target)
    {
        prev->next = target->next;
        delete target;
    }
}

void SinglyLinkedList::circularInsert(int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        head->next = head;
        return;
    }

    Node* inserted = new Node(head->next, head->data);
    head->data = data;
    head->next = inserted;
}

Node* SinglyLinkedList::circularFind(int data)
{
    Node* curr = head;
    while (curr != nullptr && curr->data != data)
    {
        curr = curr->next;
        if (curr == head)
        {
            return nullptr;
        }
    }
    return curr;
}

void SinglyLinkedList::circularRemove(Node* target)
{
    if (head == nullptr || target == nullptr)
    {
        return;
    }

    if (head->next == head && head == target)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* next = target->next;
    target->data = next->data;
    target->next = next->next;
    if (next == head)
    {
        head = target;
    }
    delete next;
}