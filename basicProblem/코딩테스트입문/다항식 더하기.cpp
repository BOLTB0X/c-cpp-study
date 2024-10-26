#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    string temp;
    vector<string> v;
    stringstream ss(polynomial);
    
    int poly[2] = {0, 0};
    
    while (getline(ss, temp, ' ')) {
        v.push_back(temp);
    }
    
    for (const string st: v) {
        if (st[0] == '+') continue;
        
        if (st.find('x') != string::npos) {
            if (st[0] == 'x')
                poly[0]++;
            else
                poly[0] += stoi(st.substr(0, st.find('x')));
        } else {
            poly[1] += stoi(st);
        }
        
    }
    
    if (poly[0] == 0) 
        return to_string(poly[1]);
    else {
        string x;
        
        if (poly[0] == 1) 
            x = "x";
        else 
            x = to_string(poly[0]) + "x";
        
        if (!poly[1]) 
            return x;
        else 
            return x + " + " + to_string(poly[1]);
    }
        
    return "0";
}