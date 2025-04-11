#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    set<int> primes;
    int number = 2;
    
    while (number <= n) {
        if (!(n % number)) {
            primes.insert(number);
            n /= number;
        }
        else number++;
    }
    
    answer.assign(primes.begin(), primes.end());
    return answer;
}