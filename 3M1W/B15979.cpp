#include<iostream>
using namespace std;


int gcd(int a, int b) {
    int temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int M, N;
    cin >> M >> N;

    if (M < 0) M *= -1;
    if (N < 0) N *= -1;

    if ((M == 0) | (N == 0)) {
        if ((M == 0) & (N == 0)) {
            cout << 0;
        }
        else if ((M == 1) | (N == 1)) {
            cout << 1;
        }
        else cout << 2;
    }
    else if (gcd(M,N) == 1) cout << 1;
    else cout << 2;
}

// swap(a,b) 도 가능하다
// abs(a), abs(b) 도 가능하다
// 아래 조건은 다음과 같이 간단하게 표현 가능
// if (!a && !b) cout << 0;
// else if (gcd(a, b) == 1) cout << 1;
// else cout << 2;