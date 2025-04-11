#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e) {
    string temp = my_string.substr(s, e - s + 1);
    reverse(temp.begin(), temp.end());
    return my_string.substr(0, s) + temp + my_string.substr(e+1);
}