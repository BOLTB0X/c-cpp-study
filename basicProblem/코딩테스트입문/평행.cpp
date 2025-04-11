#include <string>
#include <vector>

using namespace std;

double gradiant(vector<int> p1, vector<int> p2) {
    return (double)(p1[1] - p2[1]) / (p1[0] - p2[0]);
}

int solution(vector<vector<int>> dots) {
    if (gradiant(dots[0], dots[1]) == gradiant(dots[2], dots[3]) ||
        gradiant(dots[0], dots[2]) == gradiant(dots[1], dots[3]) ||
        gradiant(dots[0], dots[3]) == gradiant(dots[1], dots[2])) {
        return 1;
    }
    return 0;
}