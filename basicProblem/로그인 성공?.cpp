#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    
    for (const vector<string> v: db) {
        if (v[0] == id_pw[0] && v[1] == id_pw[1])
            return "login";
        
        else if (v[0] == id_pw[0] && v[1] != id_pw[1])
            return "wrong pw";
    }
    return "fail";
}