#include <string>
#include <vector>

using namespace std;

int combination(int n, int r){
    if (n == r || r == 0) 
        return 1; 
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

int solution(int balls, int share) {
    return combination(balls, share);
}