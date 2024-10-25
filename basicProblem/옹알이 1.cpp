#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string bab[4] = { "aya", "ye", "woo", "ma" };
bool visited[4] = {false, false, false, false};

vector<string> permutations;

string join(vector<string> v) {
    string res;
    
    for (const string s: v)
        res += s;
    
    return res;
}

void DFS(vector<string> v, int r, int depth) {
    if (r == depth) {
        permutations.push_back(join(v));
        return;
    }
    
    for (int i = 0; i <4; ++i) {
        if (visited[i]) continue;
        
        visited[i] = true;
        v.push_back(bab[i]);
        DFS(v, r, depth + 1);
        visited[i] = false;
        v.pop_back();
    }
    return;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 1; i <= 4; ++i) {
        DFS({}, i, 0);
    }
    
    for (const string b: babbling) {
        if (find(permutations.begin(), permutations.end(), b) != permutations.end())
            answer++;
    }
    
    return answer;
}