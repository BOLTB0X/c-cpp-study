#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for (char& ch: myString) {
        if (ch == 'A') ch = 'B';
        else ch = 'A';
    }
    
    return myString.find(pat) != string::npos;
}