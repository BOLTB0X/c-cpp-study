#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long get_dec(string bin) {
    long long res = 0;
    
    for (int i = bin.size() - 1, j = 1; i >= 0; --i, j *= 2) {
        res += (long long)(bin[i] - '0') * j;
    }
    
    return res;
}

string get_bin(long long n) {
    string res;
    
    if (!n) return "0";
    
    while (n > 0) {
        res.push_back(n % 2 + '0');
        n /= 2;
    }
        
    reverse(res.begin(), res.end());
    
    return res;
}

string solution(string bin1, string bin2) {
    return get_bin(get_dec(bin1) + get_dec(bin2));
}