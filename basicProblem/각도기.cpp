#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    switch (angle) {
        case 0 ... 89:
            return 1;
        case 90:
            return 2;
        case 91 ... 179:
            return 3;
        case 180:
            return 4;
    }
    return 0;
}