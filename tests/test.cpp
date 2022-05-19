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