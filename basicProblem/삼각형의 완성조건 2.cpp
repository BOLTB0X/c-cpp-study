#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int min_value = 1001;
    
    for (const int side: sides) {
        if (min_value > side) min_value = side;
    }
    return min_value * 2 - 1;
}