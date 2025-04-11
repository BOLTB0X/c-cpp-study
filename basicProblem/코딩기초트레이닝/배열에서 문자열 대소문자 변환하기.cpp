#include <string>
#include <vector>

using namespace std;

string convert_upper(string str) {
    for (char &ch: str) {
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
    }
    return str;
}

string convert_lower(string str) {
    for (char &ch: str) {
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;
    }
    return str;
}

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for(int i = 0; i < strArr.size(); ++i) {
        if (i % 2) {
            answer.push_back(convert_upper(strArr[i]));
        } else {
            answer.push_back(convert_lower(strArr[i]));
        }
    }
    return answer;
}