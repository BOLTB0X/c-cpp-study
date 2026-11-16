#include <iostream>

int* CreateValue()
{
    int value = 100;

    return &value;
}

int main()
{
    int* ptr = CreateValue();

    std::cout << *ptr;

    return 0;
}