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
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cnt, result;
    cin >> N;
    result = 1;
    if (!N) result = 0;
    if (N > 1) {
        if (N % 3 == 0) cnt = N / 3;
        if (N % 3 == 1) result = 4, cnt = (N - 4) / 3;
        if (N % 3 == 2) result = 2, cnt = (N - 2) / 3;
        while (cnt--) result = (result * 3) % MOD;
    }
    cout << result;
    return 0;
}