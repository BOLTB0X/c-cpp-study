#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string strA = to_string(a), strB = to_string(b);
    
    if (stoi(strA + strB) >= 2 * a * b) {
        return stoi(strA + strB);
    }
    return 2 * a * b;
}