#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    switch (n) {
        case 1:
            answer = vector<int>(num_list.begin(), num_list.begin() + slicer[1] + 1);
            break;
        case 2:
            answer = vector<int>(num_list.begin() + slicer[0], num_list.end());
            break;
        case 3:
            answer = vector<int>(num_list.begin() + slicer[0], num_list.begin() + slicer[1] + 1);
            break;
        default:
            for (int i = slicer[0]; i <= slicer[1]; i+= slicer[2])
                answer.push_back(num_list[i]);
            break;
    }
    return answer;
}