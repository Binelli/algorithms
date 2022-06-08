#include "doubly-linked-list.h"

DoublyLinkedList::~DoublyLinkedList()
{
    if (head != nullptr)
    {
        DLLNode *next = head->next;
        while (next != nullptr && next != head)
        {
            DLLNode* tmp = next->next;
            delete next;
            next = tmp;
        }

        delete head;
    }
}



DLLNode* DoublyLinkedList::insert(int data)
{
    if (head == nullptr)
    {
        head = new DLLNode(data);
        return head;
    }

    DLLNode *prev = head->prev;
    DLLNode *inserted = new DLLNode(prev, head, data);
    head->prev = inserted;
    prev->next = inserted;
    head = inserted;
    return head;
}

DLLNode* DoublyLinkedList::front()
{
    return head;
}

DLLNode* DoublyLinkedList::find(int value)
{
    DLLNode* current = head;
    while (current != nullptr && current->data != value)
    {
        current = current->next;
        if (current == head)
        {
            return nullptr;
        }
    }
    return current;
}

void DoublyLinkedList::remove(DLLNode* node)
{
    if (head->next == head)
    {
        if (head == node)
        {
            delete head;
            head = nullptr;
        }
        return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (head == node)
    {
        head = node->next;
    }

    delete node;
}