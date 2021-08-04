#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<int> numTok(int X) {
    vector<int> result;
    result.resize(10, 0);
    while (X) {
        result[X % 10]++;
        X /= 10;
    }
    return result;
}

bool isCorrect(vector<int> A, vector<int> B, vector<int> C) {
    for (int i = 0; i < 10; i++) if (A[i] != B[i] + C[i]) return false;
    return true;
}

bool isVN(int X) {
    vector<int> A, B, C;
    A = numTok(X);
    for (int i = 2; i <= sqrt(X); i++) {
        if (X % i == 0) {
            B = numTok(i), C = numTok(X / i);
            if (isCorrect(A, B, C)) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while (true) {
        cin >> N;
        if (!N) break;
        while (!isVN(N)) N++;
        cout << N << '\n';
    }
    
}