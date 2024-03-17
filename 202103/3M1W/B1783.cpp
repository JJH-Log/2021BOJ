#include<iostream>
using namespace std;

int main()
{
    int N, M, result;

    cin >> N >> M;
    result = 0;

    if (N == 1) {
        result = 1;
    }
    else if (N == 2) {
        result = (M - 1) / 2 + 1;
        if (result > 4) result = 4;
    }
    else if (N >= 3) {
        if (M < 7) {
            result = M;
            if (result > 4) result = 4;
        }
        else {
            result = M - 2;
        }
    }
    cout << result;

    return 0;
}

//내가 놓친 것
//N=3 인 경우와 N>=4 인 경우를 분리해서 생각했다.
