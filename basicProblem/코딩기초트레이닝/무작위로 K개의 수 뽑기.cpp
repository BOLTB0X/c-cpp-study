#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    auto complains = [&answer](int a) {
        return find(answer.begin(), answer.end(), a) != answer.end();
    };
    
    for (const int a: arr) {
        if (answer.size() == k) break;
        if (!complains(a)) answer.push_back(a);
    }
    
    // for (int a: answer)
    //     cout << a << ' ';
    // cout << '\n';
    
    while (answer.size() < k) {
        answer.push_back(-1);
    }
    
    return answer;
}