#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if (direction == "right") {
        int las = numbers.back();
        numbers.pop_back();
        numbers.insert(numbers.begin(), las);
    } else {
        int fir = numbers.front();
        numbers.erase(numbers.begin());
        numbers.push_back(fir);
    }
    
    return numbers;
}