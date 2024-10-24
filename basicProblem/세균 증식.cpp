#include <string>
#include <vector>

using namespace std;

int pow(int a, int n) {
    int res = a;
    
    while (n > 0) {
        res *= 2;
        n--;
    }
    
    return res;
}

int solution(int n, int t) {
    return pow(n, t);
}