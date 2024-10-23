#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> sv = emergency;
    
    
    sort(sv.begin(), sv.end(), compare);
    
    for (int ele : emergency) {
        size_t p = find(sv.begin(), sv.end(), ele) - sv.begin();
        answer.push_back(p + 1);
    }
    
    return answer;
}