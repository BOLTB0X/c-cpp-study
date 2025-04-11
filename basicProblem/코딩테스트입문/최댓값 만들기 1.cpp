#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    return numbers[0] * numbers[1];
}