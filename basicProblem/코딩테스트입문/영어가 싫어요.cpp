#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(string numbers) {
    string answer = "";
    unordered_map<string, int> umap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
        {"eight", 8}, {"nine", 9}
    };
    string temp = "";
    
    for (const char ch: numbers) {
        temp.push_back(ch);
        
        if (umap.find(temp) != umap.end()) {
            answer += to_string(umap[temp]);
            temp = "";
        }
    }
    
    return stoll(answer);
}