#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(double a, double b) {
    return a > b;
}

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<double> avg;
    
    for (const vector<int> s: score) {
        avg.push_back((s[0] + s[1]) / 2.0);
    }
    
    vector<double> sort_avg = avg;
    sort(sort_avg.begin(), sort_avg.end(), compare);
    
    for (const double a: avg) {
        auto it = find(sort_avg.begin(), sort_avg.end(), a);
        answer.push_back(it - sort_avg.begin() + 1);
    }
    
    return answer;
}