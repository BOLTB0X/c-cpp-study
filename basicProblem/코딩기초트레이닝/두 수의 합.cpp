#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int carry = 0, i = a.length() - 1, j = b.length() - 1;
    
    while (carry || i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        answer.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}