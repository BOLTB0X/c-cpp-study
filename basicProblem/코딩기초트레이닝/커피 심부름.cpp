#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for (const string o: order) {
        if (o == "anything" || o.find("americano") != -1)
            answer += 4500;
        else 
            answer += 5000;
    }
    return answer;
}