#include "square-and-multiply.h"
#include "singly-linked-list.h"
#include "doubly-linked-list.h"
#include <gtest/gtest.h>

TEST(SquareAndMultiplyTest, OperationTest) {
    EXPECT_EQ(square_and_multiply(2, 4, 5), 1);
    EXPECT_EQ(square_and_multiply(457000, 649000, 567), 79);
    EXPECT_EQ(square_and_multiply(10, 0, 5), 1);
}

TEST(SinglyLinkedListTest, InsertionTest) {
    SinglyLinkedList list;
    list.insert(10);
    EXPECT_EQ(list.front()->data, 10);
    list.insert(20);
    EXPECT_EQ(list.front()->data, 20);
}

TEST(SinglyLinkedListTest, SortedInsertionTest) {
    SinglyLinkedList list;
    list.insertSorted(10);
    EXPECT_EQ(list.front()->data, 10);
    list.insertSorted(5);
    EXPECT_EQ(list.front()->data, 5);
    list.insertSorted(20);
    EXPECT_EQ(list.front()->next->next->data, 20);
    list.insertSorted(15);
    EXPECT_EQ(list.front()->next->next->data, 15);
}

TEST(SinglyLinkedListTest, FindTest) {
    SinglyLinkedList list;
    EXPECT_EQ(list.find(10), nullptr);
    list.insert(10);
    EXPECT_EQ(list.find(10)->data, 10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    EXPECT_EQ(list.find(40)->data, 40);
    EXPECT_EQ(list.find(20)->data, 20);
    EXPECT_EQ(list.find(50), nullptr);
}

TEST(SinglyLinkedListTest, RemoveTest) {
    SinglyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.remove(list.find(20));
    EXPECT_EQ(list.find(20), nullptr);
    list.insert(30);
    list.insert(40);
    list.remove(list.find(30));
    EXPECT_EQ(list.find(30), nullptr);
    list.remove(list.find(10));
    EXPECT_EQ(list.find(10), nullptr);
    list.remove(nullptr);

    SinglyLinkedList list2;
    list2.insert(10);
    list2.insert(20);

    list.remove(list2.find(20));
    EXPECT_EQ(list.find(10), nullptr);
}

TEST(SinglyLinkedListTest, CircularInsertTest) {
    SinglyLinkedList list;
    list.circularInsert(10);
    EXPECT_EQ(list.find(10)->next->data, 10);

    list.circularInsert(20);
    EXPECT_EQ(list.find(20)->next->data, 10);

    list.circularInsert(30);
    EXPECT_EQ(list.find(30)->next->data, 20);
}

TEST(SinglyLinkedListTest, CircularFindText) {
    SinglyLinkedList list;
    EXPECT_EQ(list.circularFind(10), nullptr);

    list.circularInsert(10);
    EXPECT_EQ(list.circularFind(10)->data, 10);
    EXPECT_EQ(list.circularFind(20), nullptr);

    list.circularInsert(20);
    list.circularInsert(30);
    EXPECT_EQ(list.circularFind(30)->data, 30);
    EXPECT_EQ(list.circularFind(20)->data, 20);
    EXPECT_EQ(list.circularFind(40), nullptr);
}

TEST(SinglyLinkedListTest, CircularRemoveTest) {
    SinglyLinkedList list;
    list.circularInsert(10);
    list.circularRemove(list.circularFind(10));
    EXPECT_EQ(list.front(), nullptr);

    list.circularInsert(10);
    list.circularInsert(20);
    list.circularInsert(30);
    list.circularRemove(list.circularFind(30));
    EXPECT_EQ(list.front()->data, 20);

    list.circularRemove(list.circularFind(10));
    EXPECT_EQ(list.front()->data, 20);
}

TEST(SinglyLinkedListTest, MidPoint) {
    SinglyLinkedList list;
    EXPECT_EQ(list.mid(), nullptr);

    list.insert(10);
    EXPECT_EQ(list.mid()->data, 10);

    list.insert(20);
    EXPECT_EQ(list.mid()->data, 20);

    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.insert(70);
    EXPECT_EQ(list.mid()->data, 40);
}

TEST(SinglyLinkedListTest, KthFromTheEnd) {
    SinglyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.insert(70);

    EXPECT_EQ(list.kthFromTheEnd(0)->data, 10);
    EXPECT_EQ(list.kthFromTheEnd(2)->data, 30);
    EXPECT_EQ(list.kthFromTheEnd(5)->data, 60);
    EXPECT_EQ(list.kthFromTheEnd(6)->data, 70);
    EXPECT_EQ(list.kthFromTheEnd(7)->data, 70);
}

TEST(DoublyLinkedListTest, CircularDLLInsertTest) {
    DoublyLinkedList list;
    EXPECT_EQ(list.front(), nullptr);

    list.insert(10);
    EXPECT_EQ(list.front()->data, 10);

    list.insert(20);
    EXPECT_EQ(list.front()->data, 20);

    list.insert(30);
    EXPECT_EQ(list.front()->data, 30);
}

TEST(DoublyLinkedListTest, CircularDLLFindTest) {
    DoublyLinkedList list;
    EXPECT_EQ(list.find(10), nullptr);

    list.insert(50);
    list.insert(20);
    list.insert(10);
    list.insert(5);

    EXPECT_EQ(list.find(50)->data, 50);
    EXPECT_EQ(list.find(10)->data, 10);
    EXPECT_EQ(list.find(5)->data, 5);
    EXPECT_EQ(list.find(30), nullptr);
}

TEST(DoublyLinkedListTest, CircularDLLRemoveTest) {
    DoublyLinkedList list;
    list.insert(50);
    list.remove(list.find(50));
    EXPECT_EQ(list.front(), nullptr);

    list.insert(50);
    list.insert(20);
    list.insert(10);
    list.insert(5);

    list.remove(list.find(10));
    EXPECT_EQ(list.find(10), nullptr);
}