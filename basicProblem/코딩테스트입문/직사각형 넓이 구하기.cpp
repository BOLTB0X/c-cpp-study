#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int max_w = -256, min_w = 256, max_h = -256, min_h = 256;
    
    for (const vector<int> dot: dots) {
        if (max_w < dot[0]) {
            max_w = dot[0];
        }
        
        if (min_w > dot[0]) {
            min_w = dot[0];
        }
        
        if (max_h < dot[1]) {
            max_h = dot[1];
        }
        
        if (min_h > dot[1]) {
            min_h = dot[1];
        }
    }
    
    return (max_w - min_w) * (max_h - min_h);
}