#include <iostream>

int main()
{
    int* number = new int(100);

    std::cout << *number << std::endl;

    delete number;
    number = nullptr;

    return 0;
}