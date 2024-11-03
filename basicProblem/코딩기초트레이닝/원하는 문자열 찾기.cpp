#include <string>
#include <vector>

using namespace std;

string convert_lower(string s) {
    string res = "";
    
    for (const char ch: s) {
        if (ch >= 'A' && ch <= 'Z')
            res.push_back(ch + 32);
        else
            res.push_back(ch);
    }
    
    return res;
}

int solution(string myString, string pat) {
    if (myString.size() < pat.size()) return 0;
    
    pat = convert_lower(pat);
    
    for (int i = 0; i <= myString.size() - pat.size(); ++i) {
        string temp = myString.substr(i, pat.size());
        if (convert_lower(temp) == pat) return 1;
    }
    return 0;
}