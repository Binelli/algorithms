#include "square-and-multiply.h"

#include <iostream>
#include <string>

using namespace std;

void compare(int result, int expected, string testCase)
{
    if (result != expected)
    {
        cout << testCase << " failed. Expected: " << expected << " got: " << result << endl;
    }
    else
    {
        cout << testCase << " OK" << endl;
    }
}

int main(int argc, char *argv[])
{
    compare(square_and_multiply(2, 4, 5), 1, "test1");
    compare(square_and_multiply(37, 45, 7), 1, "test2");
    compare(square_and_multiply(457000, 649000, 567), 79, "test3");
    compare(square_and_multiply(10, 0, 5), 1, "test4");

    return 0;
}