#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "", temp;
    stringstream ss(my_string);
    
    while (getline(ss, temp, letter[0])) {
        answer += temp;
    }
    return answer;
}