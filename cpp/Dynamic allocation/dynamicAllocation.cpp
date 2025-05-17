#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int* p = new int;         // int 1개
    int* arr = new int[5];    // int 5개 (배열)
    
    cout << "p: " << p << ' ' << "arr: " << arr << '\n';
    // 주소값 출력
    // 

    for (int i = 0; i < 5; i++) {
        arr[i] = i;

        cout << arr[i] << ' ';
    }
    cout << '\n';

    delete p;

    int* newArr = new int[10];
    copy(arr, arr + 5, newArr);

    delete[] arr;
    arr = newArr;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}