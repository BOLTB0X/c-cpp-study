#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {    
    for (const string d: dic) {
        bool flag = true;
        
        for (const string s: spell) {
            if (d.find(s) != string::npos) continue;
            
            flag = false;
            break;
        }
        
        if (flag) return 1;
    }
    return 2;
}