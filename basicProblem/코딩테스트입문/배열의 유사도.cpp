#include <string>
#include <vector>

using namespace std;

bool contains(vector<string> v, string st) {
    for (const string ele: v) {
        if (ele == st) return true;
    }
    return false;
}

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for (const string ele: s1) {
        if (contains(s2, ele)) answer++;
    }
    return answer;
}