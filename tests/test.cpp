#include "square-and-multiply.h"
#include "singly-linked-list.h"
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