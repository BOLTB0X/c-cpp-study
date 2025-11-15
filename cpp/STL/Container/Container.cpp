#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> data = {30, 10, 40, 20};

std::sort(data.begin(), data.end());

for (int val : data) {
    std::cout << val << " "; // 10 20 30 40
}