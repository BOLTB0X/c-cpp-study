#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string strA = to_string(a), strB = to_string(b);
    
    if (stoi(strA + strB) >= stoi(strB + strA))
        return stoi(strA + strB);
    
    return stoi(strB + strA);
}