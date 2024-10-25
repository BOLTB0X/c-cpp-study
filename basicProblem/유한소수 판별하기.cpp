#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

vector<int> get_factor(int n) {
    vector<int> res;
    int d = 2;
    
    while (d <= n) {
        if (!(n % d)) {
            n /= d;
            if (find(res.begin(), res.end(), d) != res.end())
                continue;
            res.push_back(d);
            
        } else {
            d++;
        }
    }
    
    return res;
}

int solution(int a, int b) {
    vector<int> ret = get_factor(b / gcd(a, b));
    
    for (int r : ret) {
        if (r == 2 || r == 5) {
            continue;
        }
        
        return 2;
    }
        
    return 1;
}