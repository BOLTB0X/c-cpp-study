#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    return sqrt(n) == (int)sqrt(n) ? 1 : 2;
}