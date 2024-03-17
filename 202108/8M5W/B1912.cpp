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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, N, temp;
    int total, best_total, best;
    total = 0, best = MININT; best_total = MININT;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> temp;
        best = max(best, temp);
        if (temp < 0 && temp + total < 0)  total = 0;
        else total += temp, best_total = max(best_total, total);
    }
    if (best <= 0) cout << best;
    else cout << best_total;
    return 0;
}