#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    int size[31] = {0, };
    
    for (const string str: strArr) {
        size[str.length()]++;
        answer = answer > size[str.length()] ? answer: size[str.length()];
    }
    
    return answer;
}