#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int size = my_string.size();
    
    for (int i = 0; i < size; ++i) {
        if (my_string.substr(size - 1 - i) == is_suffix)
            return 1;
    }
    return 0;
}