#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void abssort(float* x, unsigned n) {
    sort(x, x + n, [](float a, float b) {
            return (abs(a) < abs(b));
        }
    );
}

int main(void) {
    int x = 1, y = 2;
    float numbers[5] = {4, -3, 5, -1, 2};

    auto add = [](int a, int b) -> int {
        return a + b;
    };

    auto refe = [=, &y]() {
        y += x;
    };

    refe();
    cout << x << ' ' << y << '\n'; // 1 3

    cout << add(1, 2) << '\n';

    abssort(numbers, 5);

    for (int i = 0; i < 5; ++i) {
        cout << numbers[i] << ' ';
        // -1 2 -3 4 5
    }
    cout << '\n';

    return 0;
}